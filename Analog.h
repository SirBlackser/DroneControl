
#ifndef ANALOG_H
#define ANALOG_H

/**
Initialization of the ADC
*/
void AnalogInit(void);			//Initialize ADC system

/**
Get the value of the provided channels
@verbatim
Get analog channel value
ChannelPos:
	Differential mode: positive input pin (0 to 15)
	Single ended mode: input pin (0 to 15)
ChannelNeg:
	Differential mode: negative input pin (0 to 7)
	Single ended mode: write '-1' to select single ended mode
Return value:
	-2048 to 2047 (signed) or 0 to 4095 (unsigned)
	10000: Invalid channel settings
@endverbatim
@param ChannelPos pin 0 to 15
@param ChannelNeg pin 0 to 7 (Select -1 for single ended mode)
@return int -2048 to 2047
*/
int AnalogGetCh(int ChannelPos,int ChannelNeg);
								

#endif