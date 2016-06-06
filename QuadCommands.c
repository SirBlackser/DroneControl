/*
 * QuadCommands.c
 *
*/
#include <stdio.h>

	long sequence;
static char droneIP[] = "192.168.1.1";		//dit zal wss nog nodig zijn, maar niet hier.
static long takeOfff = 290718208;
static long landd = 290717696;
static long stop = 290717952;

void QuadCommands(void)
{
	sequence = 0;
}

//AT command with sequence number 1 will reset the counter.
long getSeq(void)
{
	sequence++;
	return sequence;
}

//send to port 5556
void takeOff()
{
	printf("AT*REF=%ld,%ld\r", getSeq(), takeOfff);
}

//send to port 5556
void land()
{
	printf("AT*REF=%ld,%ld\r", getSeq(), landd);
}

//send to port 5556
void emergency()
{
	printf("AT*REF=%ld,%ld\r", getSeq(), stop);
}

void config()
{
	printf("AT*CONFIG=%ld,\"general:navdata_demo\",\"TRUE\"\r", getSeq());
}

/*
void ctrl(void)
{
	printf("AT*CTRL=0");
}
*/

void pmode()
{
	printf("AT*PMODE=%ld,2\r", getSeq());
}

void misc()
{
	printf("AT*MISC=%ld,2,20,2000,3000\r", getSeq());
}

void trim()
{
	printf("AT*FTRIM=%ld\r", getSeq());
}

//set variables to steer the copter
//send to port 5556
void updateDrone(long* roll, long* pitch, long* vSpeed, long* turn)
{
	printf("AT*PCMD=%ld,%d,%ld,%ld,%ld,%ld\r", getSeq(), 1, *roll, *pitch, *vSpeed, *turn);
}

void watchdog()
{
	sequence = 0; //1
	printf("AT*COMWDG=%dl\r", getSeq());
	//printf("AT*COMWDG\r");
}


void setMaxAltitude(int altitude)	//value between 500 and 5000 -> centimeters
{
	printf("AT*CONFIG=%ld,\"control:altitude_max\",\"%d\"",getSeq(), altitude);
}

void setMinAltitude(int altitude)	//Should be left to its default value
{
	printf("AT*CONFIG=%ld,\"control:altitude_min\",\"%d\"", getSeq(), altitude);
}
