#ifndef DEBUGUSART_H
#define DEBUGUSART_H


#define USART USARTD0			//Oorspronkelijk USARTD0 - ATLYS USARTC0
#define USART_PORT PORTD		//Oorspronkelijk PORTD - ATLYS PORTC

void debugUSARTInit(void); //Initialize USART, bind to stdin,stdout

#endif