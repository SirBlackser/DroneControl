#include "usart.h"
#include <avr/io.h>
#include <stdio.h>

static int stdio_putchar(char c, FILE * stream);
static int stdio_getchar(FILE *stream);
//Separate streams for in and out. (Not really needed)
static FILE UsartStdo = FDEV_SETUP_STREAM(stdio_putchar, NULL,_FDEV_SETUP_WRITE);
static FILE UsartStdi = FDEV_SETUP_STREAM(NULL, stdio_getchar,_FDEV_SETUP_READ);
//int interrupts = 1;

void USARTInit(void)
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
	
	//USART.BAUDCTRLA = 0xD7; //BSEL = 983, BSCALE = -7 115200 baud
	//USART.BAUDCTRLB = 0x93;
	
	stdin=&UsartStdi;
	stdout=&UsartStdo;
}


static int stdio_putchar(char c, FILE * stream)
{
	while (!(USART.STATUS & USART_DREIF_bm));
	USART.DATA = c;
	return 0;
}
	

static int stdio_getchar(FILE *stream)
{
	//Wait until data has been received.
	while( !(USART.STATUS & USART_RXCIF_bm) );
	char data = USART.DATA;
	if(data == '\r')
		data = '\n';
	return data;
}

void sendChar(char c)
{
	
	while( !(USART.STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USART.DATA = c;
	
}

void sendString(char *text)
{
	while(*text)
	{
		sendChar(*text++);
	}
}

/*
ISR(USART_RXC_vect)
{
	;
}
*/