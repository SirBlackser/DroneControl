#ifndef USART_H
#define USART_H


#define USART USARTC0			//Oorspronkelijk USARTD0 - ATLYS USARTC0
#define USART_PORT PORTC		//Oorspronkelijk PORTD - ATLYS PORTC

/**
Initializes the USART and configures stdio.
*/
void USARTInit(void); //Initialize USART, bind to stdin,stdout

#endif