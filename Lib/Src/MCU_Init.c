#include "main.h"
#include "MCU_Init.h"



void GPIO_Init(){
	DDRD |= (1 << Led_Blue)|(1 << Led_Red);
	PORTD &= ~((1 << Led_Blue)|(1 << Led_Red));
}