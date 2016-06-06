/* XBee driver
*/
#include <stdio.h>
#include "XDriver.h"
#include "Colors.h"

char cc = '+';

//UART-SPI MODE (SPI mode onmogelijk met huidige opstelling)

//-----------------------------------------------------------------------------
//Addressing

//Destination IP
//tested and confirmed.
bool setDestinationIP(char c[])			//Valid ipv4 (ASCII)
{
	if(ATEnable())
	{
		printf("ATDL%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "Destination IP is set to: %s #success!"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "Destination IP set failed!"     ANSI_COLOR_RESET "\n");
			return false;
		}
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tested and confirmed.
char * getDestinationIP(void)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATDL\r");
		scanf("%s", c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "Destination IP is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//set the IP address
//tested & confirmed
bool setIP(char c[])
{
	if(ATEnable())
	{
		printf("ATMY%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "IP address changed to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to change IP Address"     ANSI_COLOR_RESET "\n", c);
			return false;
		}
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//get the IP address
//tested & confirmed
char * getIP(void)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATMY\r");
		scanf("%s", c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "IP address is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Subnet Mask
//tested & succeeded.
bool setMask(char c[])			//Valid ipv4 (ASCII)
{
	if(ATEnable())
	{
		printf("ATMK%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "subnetmask is changed to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to change subnetmask"     ANSI_COLOR_RESET "\n", c);
			return false;
		}
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tested & succeeded.
char * getMask(void)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATMK\r");
		scanf("%s", c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "subnetmask is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//IP of Gateway
//tried and tested
bool setGateway(char c[])			//Valid ipv4 (ASCII)
{
	if(ATEnable())
	{
		printf("ATGW%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "Gateway changed to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to set gateway"     ANSI_COLOR_RESET "\n", c);
			return false;
		};
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tried & tested
char * getGateway(void)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATGW\r");
		scanf("%s", c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "Gateway is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Serial number High
//tried & tested
char * getSerialNumberHigh(void)	//2 bytes (16 bits)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATSH\r");
		scanf("%s", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "Serial number high is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Serial number Low
//tried & tested
char * getSerialNumberLow(void)	//4 bytes (32 bits)
{
	char * c[32];
	if(ATEnable())
	{
		printf("ATSL\r");
		scanf("%s", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "serial number low is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Node Identifier
//tried & tested but identifier to short.
//vb. setNodeID("xbeeModule") -> getNodeId() => result: xb
bool setNodeID(char c[])			//20 byte ASCII String
{
	if(ATEnable())
	{
		printf("ATNI%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "node ID changed to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to set node ID"     ANSI_COLOR_RESET "\n", c);
			return false;
		};
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tried & tested but identifier to short.
//see above
char * getNodeID(void)
{
	char * c[40];
	if(ATEnable())
	{
		printf("ATNI\r");
		scanf("%s", c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "node identifier is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Destination port
//tried & tested
bool setDestinationPort(char c[])			//0-65535 in hexadecimaal
{
	if(ATEnable())
	{
		printf("ATDE%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "The destination port is set to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to set destination port"     ANSI_COLOR_RESET "\n", c);
			return false;
		};
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tried & tested
char * getDestinationPort(void)
{
	char c[10];
	if(ATEnable())
	{
		printf("ATDE\r");
		scanf("%s", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "The destination port is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//Source Port
//tried & tested
bool setSourcePort(char c[])			//0-65535
{
	if(ATEnable())
	{
		printf("ATC0%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "The source port is set to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to set source port"     ANSI_COLOR_RESET "\n", c);
			return false;
		};
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tried & tested
char * getSourcePort(void)
{
	char c[30];
	if(ATEnable())
	{
		printf("ATC0\r");
		scanf("%s", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "The source port is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

//tried & tested
void setDeviceTypeIdentifier(char c[])
{
	if(ATEnable())
	{
		printf("ATDD%s\r", c);
		if(ok())
		{
			//fprintf(stderr, ANSI_COLOR_GREEN     "The Device identifier is set to: %s"     ANSI_COLOR_RESET "\n", c);
			return true;
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "failed to set device identifier"     ANSI_COLOR_RESET "\n", c);
			return false;
		};
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return false;
	}
}

//tried & tested
char * getDeviceTypeIdentifier()
{
	char c[20];
	if(ATEnable())
	{
		printf("ATDD\r");
		scanf("%s", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "The device identifier is: %s"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed"     ANSI_COLOR_RESET "\n");
		return "ERROR\r";
	}
}

int getMaxRFPayload(void)
{
	int c;
	fprintf(stderr, ANSI_COLOR_CYAN    "in function."    ANSI_COLOR_RESET "\n");
	if(ATEnable())
	{
		printf("ATNP\r");
		//fprintf(stderr, ANSI_COLOR_CYAN    "command send."    ANSI_COLOR_RESET "\n");
		scanf("%d", &c);
		//fprintf(stderr, ANSI_COLOR_GREEN     "The max payload is: %d"     ANSI_COLOR_RESET "\n", c);
		return c;
	}
}

//-----------------------------------------------------------------------------
//NETWORK CONFIGURATION

bool setDeviceOptions(char mask)
{
	if(ATEnable())
	{
		printf("ATDO%c\r", mask);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

char getDeviceOptions(void)
{
	char mask;
	if(ATEnable())
	{
		printf("ATDO\r");
		scanf("%c", &mask);
		return mask;
	}
}


//SSID
bool setSSID(char c[])			//SSID
{
	if(ATEnable())
	{
		printf("ATID%s\r", c);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

char * getSSID(void)
{
	char c[20];
	if(ATEnable())
	{
		printf("ATID\r");
		scanf("%s", c);
		return c;
	}
	else
	return "ERROR\r";
}
bool setNetworkType(int i)			//0-2 IBSSjoiner-IBSScreator-Infrastructure
{
	if(i >= 0 && i <= 2)
	{
		if(ATEnable())
		{
			printf("ATAH%d", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getNetworkType(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATAH\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}



//Protocol
bool setProtocol(int i)			//0-1 UDP-TCP
{
	if(i >= 0 && i <= 1)
	{
		if(ATEnable())
		{
			printf("ATIP%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getProtocol(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATIP\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Addressing mode
//tested & confirmed.
bool setAdressingMode(int i)			//0-1 DHCP-STATIC
{
	if(i >= 0 && i <= 1)
	{
		if(ATEnable())
		{
			printf("ATMA%d\r", i);
			if(ok())
			{
				//fprintf(stderr, ANSI_COLOR_GREEN     "Addressing mode changed."     ANSI_COLOR_RESET "\n", i);
				return true;
			}
			else
			{
				//fprintf(stderr, ANSI_COLOR_RED     "Addressing mode not changed."     ANSI_COLOR_RESET "\n");
				return false;
			}
		}
		else
		{
			//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed!"     ANSI_COLOR_RESET "\n");
			return false;
		}
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_MAGENTA     "value must be either 0 or 1, not %d"     ANSI_COLOR_RESET "\n", i);
		return false;
	}
}

//tested & confirmed.
int getAdressingMode(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATMA\r");
		scanf("%d", &i);
		//fprintf(stderr, ANSI_COLOR_GREEN     "Addressing mode is: %d"     ANSI_COLOR_RESET "\n", i);
		return i;
	}
	else
	{
		//fprintf(stderr, ANSI_COLOR_RED     "ATEnable failed!"     ANSI_COLOR_RESET "\n");
		return -1;
	}
	
}

//client timeout
bool setClientTimeout(int i)			//0-65535 ms*100
{
	if(i >= 0 && i <= 65535)
	{
		if(ATEnable())
		{
			printf("ATTM%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getClientTimeout(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATTM\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//server timeout
bool setServerTimeout(int i)			//10-65535 ms*100
{
	if(i >= 10 && i <= 65535)
	{
		if(ATEnable())
		{
			printf("ATTS%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getServerTimeout(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATTS\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//-----------------------------------------------------------------------------
//SECURITY
//Encryption Enable
bool setEncryption(int i)			//0-3 none-WPA-WPA2-WEP
{
	if(i >= 0 && i <= 3)
	{
		if(ATEnable())
		{
			printf("ATEE%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getEncryption(void)				//0-3 none-WPA-WPA2-WEP
{
	int i;
	if(ATEnable())
	{
		printf("ATEE\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Security Key (Write Only)
bool setSecurityKey(char c[])			//SSID
{
	switch (getEncryption())
	{
		case 0:
		return false;
		case 1 || 2:
		{
			if(sizeof(c) >= 0 && sizeof(c) <= 31)	//ASCII
			break;
			else
			return false;
		}
		case 3:
		{
			if(sizeof(c) == 5 || sizeof(c) == 13)	//ASCII
			break;
			else
			return false;
		}
		default:
		return false;
	}
	
	if(ATEnable())
	{
		printf("ATPK%s\r", c);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

//-----------------------------------------------------------------------------

//POWER LEVEL
bool setPowerLevel(int i)			//0-4 lowest-highest
{
	if(i >= 0 && i <= 4)
	{
		if(ATEnable())
		{
			printf("ATPL%d", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getPowerLevel(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATPL\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

int getChannel(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATCH\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//-----------------------------------------------------------------------------
//SERIAL INTERFACING
//Baud Rate
bool setBaudRate(int i)		//Valid int between 0 and '10'
{
	/*
	//Baudrate conversion
	0 = NA
	1 = 2400
	2 = 5600
	3 = 9600
	4 = 19200
	5 = 38400
	6 = 57600
	7 = 115200
	8 = 230400
	9 = 460800
	10 = 921600
	*/
	
	if(i >= 0 && i <= 10)
	{
		if(ATEnable())
		{
			printf("ATBD%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getBaudRate(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATBD\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Parity
bool setParity(int i)		//0-1-2	none-even-uneven
{
	if(i >= 0 && i <= 2)
	{
		if(ATEnable())
		{
			printf("ATNB%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getParity(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATNB\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Stop bit
bool setStopBit(int i)		//0-1	one-two stop bits
{
	if(i >= 0 && i <= 1)
	{
		if(ATEnable())
		{
			printf("ATSB%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getStopBit(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATSB\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Packetization Timeout
bool setPacketizationTimeout(int i)		//0-255	-character times
{
	if(i >= 0 && i <= 255)
	{
		if(ATEnable())
		{
			printf("ATRO%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getPacketizationTimeout(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATRO\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Flow control treshold
bool setFlowControlThreshold(int i)		//17-2233	bytes
{
	if(i >= 17 && i <= 2233)
	{
		if(ATEnable())
		{
			printf("ATFT%d\r", i);
			if(ok())
			return true;
			else
			return false;
		}
		else
		return false;
	}
	else
	return false;
}

int getFlowControlThreshold(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATFT\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//-----------------------------------------------------------------------------
//DIAGNOSTICS INTERFACING
int getFirmwareVersion(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATVR\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

int getHardwareVersion(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATHV\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

int getHardwareSeries(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATHS\r");
		scanf("%d", &i);
		//should be 0x601
		return i;
	}
	else
	return -1;
}

int getAssociationIndication(void)
{
	/*0x00 - Successfully joined an access point, established IP addresses and IP listening sockets.
	0x01 - WiFi transceiver initialization in progress.
	0x02 - WiFi transceiver initialized, but not yet scanning for access point.
	0x13 - Disconnecting from access point.
	0x23 – SSID not configured.
	0x24 - Encryption key invalid (either NULL or invalid length for WEP)
	0x27 – SSID was found, but join failed. 0x40- Waiting for WPA or WPA2 Authentication
	0x41 – Module joined a network and is waiting for IP configuration to complete, which usually means it is waiting for a DHCP provided address.
	0x42 – Module is joined, IP is configured, and listening sockets are being set up.
	0xFF– Module is currently scanning for the configured SSID.*/
	
	int i;
	if(ATEnable())
	{
		printf("ATHV\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

char * activeScan(void)
{
	/*02 – Indicates scan type of 802.11 in this format unique to S6B.
	CH - Channel number in use by access point
	ST – Security type where: 00=open, 01=WPA, 02=WPA2, and 03=WEP
	LM - Link Margin (Signal strength in dB above sensitivity)
	ID = SSID of access point found.*/
	
	char i[14];
	if(ATEnable())
	{
		printf("ATAS\r");
		scanf("%c", &i);
		return i;
	}
	else
	return -1;
}

int getTemp(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATTP\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

int getLinkMargin(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATLM\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//-----------------------------------------------------------------------------
//AT COMMAND OPTIONS

bool setTimeOut(int i)
{
	if(ATEnable())
	{
		printf("ATCT%d\r", i);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

int getTimeOut(void)
{
	int i;
	if(ATEnable())
	{
		printf("ATCT\r");
		scanf("%d", &i);
		return i;
	}
	else
	return -1;
}

//Disable command mode
bool ATDisable(void)
{
	printf("ATCN\r");
	if(ok())
	return true;
	else
	return false;
}

bool setGuardTimes(int i)
{
	if(ATEnable())
	{
		printf("ATGT%d\r", i);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

bool setCommandModeCharacter(char i)
{
	if(ATEnable())
	{
		printf("ATCC%c\r", i);
		if(ok())
		return true;
		else
		return false;
	}
	else
	return false;
}

char getCommandModeCharacter(void)
{
	char i;
	if(ATEnable())
	{
		printf("ATCC\r");
		scanf("%c", &i);
		return i;
	}
	else
	return -1;
}

//-----------------------------------------------------------------------------
//EXECUTION COMMANDS
bool applyChanges(void)
{
	printf("ATAC\r");
	if(ok())
	return true;
	else
	return false;
}

bool writeChanges(void)
{
	printf("ATWR\r");
	if(ok())
	return true;
	else
	return false;
}

bool restoreDefaults(void)
{
	printf("ATRE\r");
	if(ok())
	return true;
	else
	return false;
}

bool softwareReset(void)
{
	printf("ATFR\r");
	if(ok())
	return true;
	else
	return false;
}

bool networkReset(void)
{
	printf("ATNR\r");
	if(ok())
	return true;
	else
	return false;
}

//-----------------------------------------------------------------------------


//Configure AT command mode commands
//Enter (+++) -- Close (ATCN+carriage return)
//ascii char to hexadecimal char -> %X (internet says %02X)
//----------------------------------------------------------------------------------------------------------


bool ok(void)
{
	char c[3];
	scanf("%s", c);
	if (strcmp(c, "OK") == 0)
		return true;
	else
		return false;
}

bool ATEnable(void)
{
	//char c[3];
	printf("%c%c%c",cc, cc, cc);
	if(ok()/*strcmp(scanf("%s,c"),"OK") == 0*/)
		return true;
	else
		return false;
}

//API Enable -> Not Used

//-----------------------------------------------------------------------------
//IO Settings -> Not Used

//-----------------------------------------------------------------------------
//SLEEP COMMANDS -> Not Used

//-----------------------------------------------------------------------------
