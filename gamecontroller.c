/************************************************************************/
/* Embedded Systems														*/
/* @author Arthur Janssens & Dries Blontrock 							*/
/************************************************************************/

/**
The CPU frequency used.
*/
#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Clock.h"
#include "USART.h"
#include "Analog.h"
#include "acc.h"
#include "LED.h"
#include "switch.h"
#include <stdlib.h>
#include "XDriver.h"
#include "QuadCommands.h"
#include "DebugUsart.h"
#include "Colors.h"
#include "LcdDriver.h"

void AccLezen(void);
void init(void);
void switchAction(float, float, float);
void accControl(float, float);

int flying;	/**<Whether the drone is flying or not (This actually activates all the controls). */
signed int RawAccX, RawAccY, RawAccZ;	/**<Raw accelerometer data for further processing. */

/**
 * @brief Main program loop.
 
 * The main function contains the main program loop including activating the switchAction() and the accControl().
 */
int main(void)
{	
	//Initialize subsystems
	ClockInit();			//Initialize system clock (16 MHz)
	USARTInit();			//Initialize USART and bind to stdout,stdin
	AnalogInit();			//Initialize ADC
	AccInit();				//Initialize accelerometer system
	LEDInit();				//Initialize LEDs
	SwitchInit();			//Initialize switches
	debugUSARTInit();		//Initialize debugUSART and bind to stderr
	QuadCommands();			//set Sequence number to 0
	
	//defualt XBee command structure
	/*
	ATEnable();
	setDestinationIP("192.168.1.1");
	applyChanges();
	writeChanges();
	ATDisable();
	*/
	
	fprintf(stderr, ANSI_COLOR_RESET);
	
	resetLCD();
		
	static float f = 1000;		//this value defines the speed at which the drone flies. Higher values = slower steering (This value must not go below 1000).
	static float zero = 0;		//Template adress for float to long conversion.
	static float speed = 0.95;	//The speed at which the drone goes vertically and angular.
	float negSpeed = -speed;
	
	flying = 0;
	
	watchdog();
	_delay_ms(30);
	init();					//Initialize the drone
	_delay_ms(30);
			
	//Main program loop.		
	while(1)
	{		
		if (SwitchGet() != 0)	//start, stop, up, down, left, right
		{
			switchAction(speed, negSpeed, zero);
		}
		
		else if (flying == 1)	//Combined accelerometer control
		{
			accControl(f, zero);
		}	
	}	
	
}

/**
 * @brief Reading the raw accelerometer data.
 * 
 * This function gets the raw accelerometer data usign the AccGet@AxisRaw() command.
 */
/*void AccLezen(void)
{
	RawAccX = AccGetXAxisRaw();					//Lees waardes van ADC - Accelerometer
	RawAccY = AccGetYAxisRaw();
	RawAccZ = AccGetZAxisRaw();
}*/

/**
 * @brief Configuring the drone before takeoff.
 * 
 * A sequence of functions designed to setup some communication and control parameters for the drone.
 */
void init(void)
{
	//initialize navdata
	//initNavdata();
	
	//initialize drone
	config();
	_delay_ms(30);
	//ctrl();
	//_delay_ms(30);
	pmode();
	_delay_ms(30);
	misc();
	_delay_ms(30);
	trim();
	_delay_ms(30);
	setMaxAltitude(100);
	_delay_ms(30);
	//setMinAltitude(0);
	//_delay_ms(30);
}

/**
 * @brief Starting the drone's navData stream
 * 
 * THIS FUNCTION IS NOT YET FINISHED IT SHOULD BE USED AT YOUR OWN RISK
 */
void initNavdata()
{
	_delay_ms(1100);
	ATEnable();
	setDestinationPort("15B2");
	ATDisable();
	//data
	printf("Data");
	//data
	_delay_ms(30);
	/*
	char data[80];
	scanf("%s", data)
	//check data
	*/
	_delay_ms(1100);
	ATEnable();
	setDestinationPort("15B4");
	ATDisable();
}

/**
 * @brief Handling of the switch's input.
 * 
 * This function handles the switch's inputs and takes the corresponding action.
 @param speed The positive speed used for going up abd right (-1...1).
 @param negSpeed The negative speed used for going down and left (-1...1).
 */
void switchAction(float speed, float negSpeed, float zero)
{
	switch(SwitchGet())
	{
		/*switch
		induwen = 1
		rechts = 2
		beneden = 4
		links = 8
		boven = 16
		*/
				
		case 1 :	//TOGGLE FLYING
		{
			while(SwitchGet() == 1) {_delay_ms(25);}
			if(flying == 1)
			{
				land();
				_delay_ms(10);
				//watchdog();
				LEDSet(0x00);
				lcdClear();
				_delay_ms(30);
				lcdDrawStringG(20,100,3,2,2,"Landing",0x00, 0x00);
				flying = 0;
			}
			else
			{
				takeOff();
				_delay_ms(10);
				LEDSet(0x01);
				lcdClear();
				_delay_ms(30);
				lcdDrawStringG(20,100,3,2,2,"Flying", 0x00,0x00);
				flying = 1;
			}
		}
		case 2 :	//RIGHT
		{
			if(flying == 1)
			{
				while(SwitchGet() == 2) 
				{
					//printf("%d", posSpeed);
					updateDrone(&zero, &zero, &zero, &speed);
					_delay_ms(30);
				}
			}
		}
		case 8 :	//LEFT
		{
			if (flying == 1)
			{
				while(SwitchGet() == 8) 
				{
					//printf("%d", negSpeed);
					updateDrone(&zero, &zero, &zero, &negSpeed);
					_delay_ms(30);
				}
			}
		}
		case 16 :	//UP
		{
			if (flying == 1)
			{
				while(SwitchGet() == 16)
				{
					//printf("%d", posSpeed);
					updateDrone(&zero, &zero, &speed, &zero);
					_delay_ms(30);
				}
			}
		}
		case 4 :	//DOWN
		{
			if (flying == 1)
			{
				while(SwitchGet() == 4)
				{
					//printf("%d", negSpeed);
					updateDrone(&zero, &zero, &negSpeed, &zero);
					_delay_ms(30);
				}
			}
		}
	}	
}

/**
 * @brief Sending correct accelerometer data to the drone for complete control.
 * 
 * Sending processed raw accelerometer data to the drone using the updateDrone command in QuadCommands.
 */
void accControl(float f, float zero)
{
	//AccLezen();
	int x = AccGetXAxis(AccGetXAxisRaw());
	int y = AccGetYAxis(AccGetYAxisRaw());
	
	float x2, y2;
	
	if(x > 200)
		x2 = (x-200)/f;
	else if(x < -200)
		x2 = (x+200)/f;
	else
		x2 = 0;
	
	if(y > 200)
		y2 = -(y-200)/f;
	else if (y < -200)
		y2 = -(y+200)/f;
	else
		y2 = 0;
	
	if(y2 == 0 && x2 == 0)
	{
		//Do nothing;
	}
	else
	{
		updateDrone(&x2, &y2, &zero, &zero);
	}
	_delay_ms(30);
}

/**
 * @brief Reset the LCD-Display.
 * 
 * Resets the LCD-Display. This command will take some time to complete.
 */
void resetLCD()
{
	PORTA.DIR = PORTA.DIR | 0b00100000;
	PORTA.OUT = (PORTA.OUT & 0b11011111);
	_delay_ms(10);
	PORTA.OUT = (PORTA.OUT | 0b00100000);
	_delay_ms(2000);
	fprintf(stderr, "U");
	_delay_ms(10);
	//Optional code but really fun :D
	lcdReplaceBackground(10);
	_delay_ms(3000);
	lcdLine(0,30,240,30,0b00000000, 0b00011111);
	_delay_ms(200);
	lcdDrawStringG(20, 50, 2,2,2,"This LCD has been configured(and reset) by Arthur and     Dries.",0b00000111, 0b11100000);
	_delay_ms(200);
	lcdLine(0,190,240,190,0b00000000, 0b00011111);
	_delay_ms(20);
	lcdDrawEllipse(120,255,100,30,0b11111000, 0x00);
	_delay_ms(20);
	lcdDrawEllipse(120,255,78,25,0b00000000,0b00011111);
	_delay_ms(20);
	lcdDrawEllipse(120,255,66,20,0b01111111, 0b11100000);
	_delay_ms(20);
	lcdDrawEllipse(120,255,50,15,0xFF, 0xFF);
	_delay_ms(20);
	lcdDrawEllipse(120,255,33,10,0b11111011, 0b11100000);
	_delay_ms(20);
	lcdDrawEllipse(120,255,15,8,0b00000000, 0b00000000);
	//Optional code but really fun :D
	
}