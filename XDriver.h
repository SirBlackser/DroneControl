#ifndef XDriver_H
#define XDriver_H

//COMMANDS IN COMMENTS ARE PLANNED FOR IMPLEMENTATION
//ALL COMMANDS HAVE YET TO BE TESTED (EXCEPT A FEW)

//ALL COMMANDS' RETURN VALUES HAVE TO BE CHECKED FOR ERRORS

typedef enum { false, true } bool;
//-----------------------------------------------------------------------------	
//ADDRESSING
/**
@brief Destination Address Low.

Set the IPv4 destination address.
@param char[] Valid IPv4 address in dotted decimal notation.
*/
bool setDestinationIP(char []);
/**
@brief Destination Address Low.

Get the IPv4 destination address.
@return char[] Valid IPv4 address in dotted decimal notation.
*/
char * getDestinationIP(void);
/**
@brief IP Network Address.

Set the module's IPv4 address.
@param char[] Valid IPv4 address in dotted decimal notation.
*/
bool setIP(char []);
/**
@brief IP Network Address.

Get the module's IPv4 address.
@return char[] Valid IPv4 address in dotted decimal notation.
*/
char * getIP(void);
/**
@brief IP Address Mask.

Set the module's IPv4 mask.
@param char[] Valid IPv4 address in dotted decimal notation.
*/
bool setMask(char []);
/**
@brief IP Address Mask.

Get the module's IPv4 address.
@return char[] Valid IPv4 address in dotted decimal notation.
*/
char * getMask(void);
/**
@brief Gateway IP address.

Set the module's IPv4 gateway.
@param char[] Valid IPv4 address in dotted decimal notation.
*/
bool setGateway(char []);
/**
@brief Gateway IP address.

Get the module's IPv4 gateway.
@return char[] Valid IPv4 address in dotted decimal notation.
*/
char * getGateway(void);
/**
@brief Serial Number High.

Read the high 16 bits of the module's unique 48-bit address.
@param long range 0 - 0xFFFFFFFF
*/
char * getSerialNumberHigh(void);
/**
@brief Serial Number Low.

Read the low 32 bits of the module's unique 48-bit address.
@return long range 0 - 0xFFFFFFFF
*/
char * getSerialNumberLow(void);
/**
@brief Node Identifier.

Stores a string identifier.
@param char[] 20-Byte printable ASCII string.
*/
bool setNodeID(char []);
/**
@brief Node Identifier.

Gets the string identifier.
@return char[] 20-Byte printable ASCII string.
*/
char * getNodeID(void);
/**
@brief Destination Port.

Set destination UDP/TCP port value.
@param int range 0 - 0xFFFF
*/
bool setDestinationPort(char []);
/**
@brief Destination Port.

Get destination UDP/TCP port value.
@return int range 0 - 0xFFFF
*/
char * getDestinationPort(void);
/**
@brief Serial Communication Service Port.

Set port number used to provide the serial communication service. Data sent to this port will come out of the serial port of the module. The protocol used is set by the IP command when UART is in transparent mode.
@param int range 0 - 0xFFFF
*/
bool setSourcePort(char []);
/**
@brief Serial Communication Service Port.

Get port number used to provide the serial communication service. Data sent to this port will come out of the serial port of the module. The protocol used is set by the IP command when UART is in transparent mode.
@return int range 0 - 0xFFFF
*/
char * getSourcePort(void);
/**
@brief Device Type Identifier.

Stores a device type value. This value can be used to differentiate different XBee-based devices.
@param long range 0-0xFFFFFFFF
*/
void setDeviceTypeIdentifier(long);
/**
@brief Device Type Identifier.

Gets the device type value. This value can be used to differentiate different XBee-based devices.
@param long range 0-0xFFFFFFFF
*/
long getDeviceTypeIdentifier(void);
/**
@brief Maximum RF Payload Bytes.

This value returns the maximum number of RF payload bytes that can be sent in a transmission.
@return int range 0 - 0xFFFF
*/
int getMaxRFPayload(void);

//-----------------------------------------------------------------------------
//NETWORK
/**
@brief Device options.

Set device options.
@verbatim
Bit 0 = Enable device cloud.
Bit 1 = Enable SoftAP when ID is NULL.
Bit 2 = Enable sending transparent data to Device Cloud.
Bit 3 = Send I/O samples to both device cloud and to DL if device cloud is enabled.
Bit 4 = Send transparent data as binary data points rather than to a file.
Bit 5 = Replace a device cloud file (1) rather than append to a file (0).
Bits 6, 7- Reserved; should be 0.
@endverbatim
@param int range 0-0x03F
*/
bool setDeviceOptions(char);
/**
@brief Device options.

Get device options.
@verbatim
Bit 0 = Enable device cloud.
Bit 1 = Enable SoftAP when ID is NULL.
Bit 2 = Enable sending transparent data to Device Cloud.
Bit 3 = Send I/O samples to both device cloud and to DL if device cloud is enabled.
Bit 4 = Send transparent data as binary data points rather than to a file.
Bit 5 = Replace a device cloud file (1) rather than append to a file (0).
Bits 6, 7- Reserved; should be 0.
@endverbatim
@return int range 0-0x03F
*/
char getDeviceOptions(void);
/**
@brief SSID.

Set the SSID of the access point, which may be up to 31 ASCII characters.
@param char[] Up to 31 bytes of printable ASCII
*/
bool setSSID(char []);
/**
@brief SSID.

Get the SSID of the access point, which may be up to 31 ASCII characters.
@return char[] Up to 31 bytes of printable ASCII
*/
char * getSSID(void);
/**
@brief Network Type.

Set network type.
@param int 
@verbatim
0 = IBSS Joiner
1 = IBSS Creator
2 = Infrastructure
@endverbatim
*/
bool setNetworkType(int);
/**
@brief Network Type.

Get network type.
@return int 
@verbatim
0 = IBSS Joiner
1 = IBSS Creator
2 = Infrastructure
@endverbatim
*/
int getNetworkType(void);
/**
@brief IP Protocol.

Set the protocol used for the serial communication service.
@param int
@verbatim
0 = UDP
1 = TCP
@endverbatim
*/
bool setProtocol(int);
/**
@brief IP Protocol.

Get the protocol used for the serial communication service.
@return int 
@verbatim
0 = UDP
1 = TCP
@endverbatim
*/
int getProtocol(void);
/**
@brief IP Addressing Mode.

Set the IP addressing mode.
@param int 
@verbatim
0 = DHCP
1 = Static
@endverbatim
*/
bool setAdressingMode(int);
/**
@brief IP Addressing Mode.

Get the IP addressing mode.
@return int 
@verbatim
0 = DHCP
1 = Static
@endverbatim
*/
int getAdressingMode(void);
/**
@brief TCP timeout.

Set the timeout for connection on TCP client sockets. If 0, socket closes immediately after data sent.
@param int 0-0xFFFF [x 100 msec]
*/
bool setClientTimeout(int);
/**
@brief TCP timeout.

Get the timeout for connection on TCP client sockets. If 0, socket closes immediately after data sent.
@return int 0-0xFFFF [x 100 msec]
*/
int getClientTimeout(void);
/**
@brief TCP Server Socket Timeout.

Set the timeout for connection on a TCP server socket. This is a socket whose connection was initiated at the other end.
@param int 0x000A-0xFFFF [x 100 msec]
*/
bool setServerTimeout(int);
/**
@brief TCP Server Socket Timeout.

Get the timeout for connection on a TCP server socket. This is a socket whose connection was initiated at the other end.
@return int 0x000A-0xFFFF [x 100 msec]
*/
int getServerTimeout(void);

//-----------------------------------------------------------------------------
//SECURITY
/**
@brief Encryption Enable.

Set the encryption enable setting.
@param int
@verbatim
0 = No security
1 = WPA
2 = WPA2
3 = WEP
@endverbatim
*/
bool setEncryption(int);
/**
@brief Encryption Enable.

Get the encryption enable setting.
@return int 
@verbatim
0 = No security
1 = WPA
2 = WPA2
3 = WEP
@endverbatim
*/
int getEncryption(void);
/**
@brief Security Key.

Set the security key used for WEP, WPA, and WPA2 security. This command is write only; PK cannot be read.
@param char[] 0-31 ASCII characters for WPA and WPA2. WEP keys can be either 40 bits or 104 bits. 40-bit WEP keys are entered with 5 ASCII characters or 10 hex characters. 104-bit WEP keys are entered with 13 ASCII characters or 26 hex characters.
*/
bool setSecurityKey(char []);

//-----------------------------------------------------------------------------
//POWER
/**
@brief Power Level.

Select the power level at which the RF module transmits conducted power.
@param int 
@verbatim
0 = 0 dBm
1 = 5 dBm
2 = 10 dBm
3 = 15 dBm
4 = Max power
@endverbatim
*/
bool setPowerLevel(int);
/**
@brief Power Level.

Get the power level at which the RF module transmits conducted power.
@return int
@verbatim
0 = 0 dBm
1 = 5 dBm
2 = 10 dBm
3 = 15 dBm
4 = Max power
@endverbatim
*/
int getPowerLevel(void);
/**
@brief Channel.

Read the channel number of the access point or 0xFF if not associated.
@return int range 1-0xB
*/
int getChannel(void);

//-----------------------------------------------------------------------------
//SERIAL INTERFACING
//api enable -> NOT PLANNED FOR IMPLEMENTATION
/**
@brief Interface Data Rate.

Set the serial interface data rate for communication between the module serial port and host. Any value above 0x0A will be interpreted as an actual baud rate. When a value above 0x0A is sent, the closest interface data rate represented by the number is stored in the BD register.
@param int
@verbatim
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
@endverbatim
*/
bool setBaudRate(int);
/**
@brief Interface Data Rate.

Get the serial interface data rate for communication between the module serial port and host. Any value above 0x0A will be interpreted as an actual baud rate. When a value above 0x0A is sent, the closest interface data rate represented by the number is stored in the BD register.
@return int
@verbatim
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
@endverbatim
*/
int getBaudRate(void);
/**
@brief Serial Parity.

Set the serial parity setting on the module.
@param int
@verbatim
0 = No parity
1 = Even parity
2 = Odd parity
@endverbatim
*/
bool setParity(int);
/**
@brief Serial Parity.

Get the serial parity setting on the module.
@return int
@verbatim
0 = No parity
1 = Even parity
2 = Odd parity
@endverbatim
*/
int getParity(void);
/**
@brief Stop Bits.

Set the number of stop bits for the UART.
@param int
@verbatim
0 = 1 stop bit
1 = 2 stop bits
@endverbatim
*/
bool setStopBit(int);
/**
@brief Stop Bits.

Get the number of stop bits for the UART.
@return int
@verbatim
0 = 1 stop bit
1 = 2 stop bits
@endverbatim
*/
int getStopBit(void);
/**
@brief Packetization Timeout.

Set number of character times of inter-character silence required before packetization.
@param int range 0-0xFF [x character times]
*/
bool setPacketizationTimeout(int);
/**
@brief Packetization Timeout.

Get number of character times of inter-character silence required before packetization.
@return int range 0-0xFF [x character times]
*/
int getPacketizationTimeout(void);
/**
@brief Flow Control Threshold.

De-assert CTS when FT bytes are in the UART receive buffer
@param int range 0x11-0x823
*/
bool setFlowControlThreshold(int);
/**
@brief Flow Control Threshold.

De-assert CTS when FT bytes are in the UART receive buffer
@return int range 0x11-0x823
*/
int getFlowControlThreshold(void);

//-----------------------------------------------------------------------------
//I/O SETTINGS	-> NOT PLANNED FOR IMPLEMENTATION

//-----------------------------------------------------------------------------
//DIAGNOSTICS INTERFACING
/**
@brief Firmware Version.

Read the firmware version of the module.
@param int range 0-0xFFFF
*/
int getFirmwareVersion(void);
/**
@brief Hardware Version.

Read the hardware version of the module.
@param int range 0-0xFFFF
*/
int getHardwareVersion(void);
/**
@brief Hardware Series.

Indicates the hardware series number of the module.
@param int
*/
int getHardwareSeries(void);		//int that represents a series
/**
@brief Association Indication.

Read information regarding last node join request
@return int range 0-0xFF
@verbatim
0x00 = Successfully joined an access point, established IP addresses and IP listening sockets.
0x01 = WiFi transceiver initialization in progress.
0x02 = WiFi transceiver initialized, but not yet scanning for access point.
0x13 = Disconnecting from access point.
0x23 = SSID not configured.
0x24 = Encryption key invalid (either NULL or invalid length for WEP)
0x27 = SSID was found, but join failed. 0x40- Waiting for WPA or WPA2 Authentication
0x41 = Module joined a network and is waiting for IP configuration to complete, which usually means it is waiting for a DHCP provided address.
0x42 = Module is joined, IP is configured, and listening sockets are being set up.
0xFF = Module is currently scanning for the configured SSID.
@endverbatim
*/
int getAssociationIndication(void);
/**
THIS COMMAND IS STILL IN CONSTRUCTION
*/
char * activeScan(void);		//THIS COMMAND HAS TO BE DEBUGGED TO KNOW HOW IT'S RESPONCE IS STRUCTURED
/**
@brief Temperature.

Read temperature of module in degrees Celsius.
@return int range -30 to 85C
*/
int getTemp(void);
/**
@brief Link Margin.

Reads the received signal strength (RSSI) in terms of dB units above sensitivity. It will report 0xff until the first reception after connection to access point.
@return int range 0-0xFF
*/
int getLinkMargin(void);

//-----------------------------------------------------------------------------
//AT COMMAND OPTIONS
/**
@brief Command Mode Timeout.

Set the period of inactivity (no valid commands received) after which the RF module automatically exits AT Command Mode and returns to Idle Mode.
@param int range 2-0x1770 [x 100 ms]
*/
bool setTimeOut(int i);
/**
@brief Command Mode Timeout.

Get the period of inactivity (no valid commands received) after which the RF module automatically exits AT Command Mode and returns to Idle Mode.
@return int range 2-0x1770 [x 100 ms]
*/
int getTimeOut(void);
/**
@brief Exit Command Mode.

Explicitly exit the module from AT Command Mode. (Whether command mode is left by the CN command or by CT timing out, changes will be applied upon exit.
*/
bool ATDisable(void);
/**
@brief Guard Times.

Set required period of silence before and after the Command Sequence Characters of the AT Command Mode Sequence (GT + CC + GT). The period of silence is used to prevent inadvertent entrance into AT Command Mode.
@param int range 2-0x0576 [x 1ms] (max of 1.4 seconds)
*/
bool setGuardTimes(int i);
/**
@brief Command Mode Character.

Set the command mode character used between guard times of the AT Command Mode Sequence (GT + CC + CC + CC + GT). This sequence allows the module to enter into AT Command Mode.
@param char range 0-0xFF
*/
bool setCommandModeCharacter(char i);
/**
@brief Command Mode Character.

Get the command mode character used between guard times of the AT Command Mode Sequence (GT + CC + CC + CC + GT). This sequence allows the module to enter into AT Command Mode.
@return char range 0-0xFF
*/
char getCommandModeCharacter(void);

//-----------------------------------------------------------------------------
//SLEEP COMMANDS	-> NOT PLANNED FOR IMPLEMENTATION

//-----------------------------------------------------------------------------
//EXECUTION COMMANDS
/**
@brief Apply Changes.

Applies changes to all command registers causing queued command register values to be applied. For example, changing the serial interface rate with the BD command will not change the UART interface rate until changes are applied with the AC command. The CN command and 0x08 API command frame also apply changes.
*/
bool applyChanges(void);
/**
@brief Write.

Write parameter values to non-volatile memory so that parameter modifications persist through subsequent resets. Note: Once WR is issued, no additional characters should be sent to the module until after the "OK\r" response is received. The WR command should be used sparingly to preserve flash.
*/
bool writeChanges(void);
/**
@brief Restore Defaults.

Restore module parameters to factory defaults.
*/
bool restoreDefaults(void);
/**
@brief Software Reset.

Reset module. Responds immediately with an OK status, and then performs a software reset about 2 seconds later.
*/
bool softwareReset(void);
/**
@brief Network Reset.

Reset network layer. For WiFi, this means to disassociate from the access point and set SSID to NULL, thereby preventing the node from immediately establishing the same connection with the same access point. This command also clears security settings (EE and PK).
*/
bool networkReset(void);

//-----------------------------------------------------------------------------
//assists
/**
Waits for OK\r to be received.
*/
bool ok(void);
/**
Enables command mode.
*/
bool ATEnable(void);

//-----------------------------------------------------------------------------
#endif