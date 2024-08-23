#include <avr/io.h>
#include <util/delay.h>

#include "main.h"
#include "Buzzer.h"
#include "LCD.h"
#include "UART.h"
#include "MCU_Init.h"
#include "I2C.h"

int main(void){
	GPIO_Init();
	while (1){
		PORTD &= ~(1 << Led_Red);
		PORTD |=  (1 << Led_Blue);
		_delay_ms(1000);
		PORTD &= ~(1 << Led_Blue);
		PORTD |=  (1 << Led_Red);
		_delay_ms(1000);
	}
}

