#ifndef LED_H
#define LED_H

/**
The initialization and configuration of the leds.
*/
void LEDInit(void);			//Initialize LED system

/**
Returns the encoder status
@param bitmask char Defines the leds to be enabled B0 to B3 are usable leds.
*/
void LEDSet(char bitmask);	//Activate LEDs according to bitmask 'bitmask' B0 --> B3 are used



#endif