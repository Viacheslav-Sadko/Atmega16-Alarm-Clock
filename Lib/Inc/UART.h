#include <avr/io.h>
#include <util/delay.h>

void UART_init(unsigned int speed);
void UART_Transmit(unsigned char data);