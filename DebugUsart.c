#include "DebugUsart.h"
#include <avr/io.h>
#include <stdio.h>

static int debug_putchar(char c, FILE * debugStream);
//Write stream
static FILE UsartDebugStdo = FDEV_SETUP_STREAM(debug_putchar, NULL,_FDEV_SETUP_WRITE);
//int interrupts = 1;

void debugUSARTInit(void)
{
	USART_PORT.DIRSET=0b00001000;	
	USART_PORT.DIRCLR=0b00000100;
	
	//Zonder interrupts
	USART.CTRLA=0b00000000;
	//Activeer in en output
	USART.CTRLB=0b00011000;
	//8-bit characters
	USART.CTRLC=0b00000011;
	
	USART.BAUDCTRLA=0xE5; //BSEL=3301, BSCALE=-5 9600 baud
	USART.BAUDCTRLB=0xBC; 
	
	stderr=&UsartDebugStdo;
}


static int debug_putchar(char c, FILE * debugStream)
{
	 if (c == '\n')
	 debug_putchar('\r', debugStream);
	while (!(USART.STATUS & USART_DREIF_bm));
	USART.DATA = c;
	return 0;
}

void sendDebugChar(char c)
{
	
	while( !(USART.STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USART.DATA = c;
	
}

/*
ISR(USART_RXC_vect)
{
	;
}
*/