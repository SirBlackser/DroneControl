#ifndef QUADCOMMANDS_H_
#define QUADCOMMANDS_H_

/**
@brief Initializes the variables.
This sets the sequence number to 0.
*/
void QuadCommands(void);

/**
Returns the sequence number plus 1.
@return sequence++
*/
int getSeq(void);

/**
Sends the takeoff command.
*/
void takeOff();

/**
Sends the land command.
*/
void land();

/**
Sends the emergency command.
*/
void emergency();

/**
Sends the config command.
*/
void config(void);

/**
Sends the pmode command.
*/
void pmode(void);

/**
Sends the misc command.
*/
void misc(void);

/**
@brief Sends the trim command.
This command sets the drone's current plane as horizontal.
*/
void trim(void);

/**
Updates the drone with control data.
@param 1 roll left and right
@param 2 pitch forward and backward
@param 3 up and down
@param 4 turn left and right
*/
void updateDrone(long*, long*, long*, long*);

/**
@brief Sends the watchdog command.
Resets the drone's communication watchdog
*/
void watchdog();

/**
Sets the drone's max altitude.
@param altitude Altitude in centimeters.	(500-5000)
*/
void setMaxAltitude(int altitude);
/**
Sets the drone's min altitude.
@param altitude Altitude in centimeters.	Should be left to default, for control stability issues.
*/
void setMinAltitude(int altitude);

#endif /* QuadCommands_H_ */