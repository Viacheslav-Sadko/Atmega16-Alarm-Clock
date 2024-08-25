#include "UART.h"

void UART_init(unsigned int speed){
	UBRRH = (unsigned char)(speed>>8);
	UBRRL = (unsigned char)speed;

	UCSRB = (1 << RXEN)|(1 << TXEN);
	UCSRB |= (1 << RXCIE);
	UCSRC = (1 << URSEL)|(1 << USBS)|(1 << UCSZ1)|(1 << UCSZ0);
}

void UART_Transmit(unsigned char data) {
	while( !(UCSRA & (1 << UDRE)) );
	UDR = data;
}

void UART_Transmit_String(const char* str) {
	while (*str) { 
		UART_Transmit(*str); 
		str++; 
	}
}
