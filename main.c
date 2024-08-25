#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "stdlib.h"

#include "main.h"
#include "Buzzer.h"
#include "LCD.h"
#include "UART.h"
#include "MCU_Init.h"
#include "I2C.h"
#include "AT24C32.h"
#include "DS1307.h"
#include "Unit_test.h"
#include "Timer.h"
#include "Clock.h"

int main(void){
	
	MCU_Init();
	//sei();
	LCD_Clear();
	LCD_String("Alarm");
	while (1){
		Clock_Alarm();
	}
}

