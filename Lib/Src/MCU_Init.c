#include "main.h"
#include "MCU_Init.h"
#include "Timer.h"
#include "LCD.h"

void MCU_Init(){
	Timer_Init();
	GPIO_Init();
	LCD_Init();
	I2C_init();
	UART_init(51);
}

void GPIO_Init(){
	//Configuring Led
	DDRD  |=   (1 << Led_Blue)|(1 << Led_Red);
	PORTD &= ~((1 << Led_Blue)|(1 << Led_Red));
	//Configuring Buttons
	DDRB  &= ~((1 << Button_Ok)|(1 << Button_Set));
	PORTB |=  (1 << Button_Ok)|(1 << Button_Set);
	//Configuring Buzzer
	DDRA  |=  (1 << Buzzer);
	PORTA &= ~(1 << Buzzer);
	//Configuring LCD pins
	DDRC  =  255;
	PORTC =  0;
}