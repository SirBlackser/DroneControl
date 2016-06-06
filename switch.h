#ifndef SWITCH_H_
#define SWITCH_H_

/**
Initializes and configures the drone's switch.
*/
void SwitchInit(void);	//Initialize switches

/**
Returns the current bitmask of the switch.
@return bitmask char The bitmask of the switch.
*/
char SwitchGet(void);	//Get switch status. Switches are returned as a bitmask (B0 --> B4)


#endif 