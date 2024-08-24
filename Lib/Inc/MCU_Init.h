#include <avr/io.h>
#include "UART.h"
#include "I2C.h"

#define F_CPU 8000000UL

#define Buzzer PA0

#define Button_Set PB1
#define Button_Ok PB0
#define Led_Blue PD6
#define Led_Red PD5

void MCU_Init();
void GPIO_Init();
