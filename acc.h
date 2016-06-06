#ifndef ACC_H
#define ACC_H
/**
Initializes the accelerometer.
*/
void AccInit(void);		//Initialize accelerometer module

/**
Returns the raw data for the X-axis.
@return x uint uncalibrated data
*/
unsigned int AccGetXAxisRaw(void); //Get X axis value (uncalibrated)

/**
Returns the raw data for the Y-axis.
@return x uint uncalibrated data
*/
unsigned int AccGetYAxisRaw(void); //Get Y axis value (uncalibrated)

/**
Returns the raw data for the Z-axis.
@return x uint uncalibrated data
*/
unsigned int AccGetZAxisRaw(void); //Get Z axis value (uncalibrated)

/**
Returns the processed data for the X-axis.
@param xin	uint uncalibrated X-axis data
@return xout int calibrated data
*/
int AccGetXAxis(unsigned int AccRaw); //Calculate X axis value (in mG). Input: raw Acc value 

/**
Returns the processed data for the Y-axis.
@param yin	uint uncalibrated Y-axis data
@return yout int calibrated data
*/
int AccGetYAxis(unsigned int AccRaw); //Calculate Y axis value (in mG). Input: raw Acc value 

/**
Returns the processed data for the Z-axis.
@param zin	uint uncalibrated Z-axis data
@return zout int calibrated data
*/
int AccGetZAxis(unsigned int AccRaw); //Calculate Z axis value (in mG). Input: raw Acc value 

#endif 