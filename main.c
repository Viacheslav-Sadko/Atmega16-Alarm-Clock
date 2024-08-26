#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
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
	LCD_Clear();
	AT24C32_Read(&data_from_eeprom);
	alarm_hours = data_from_eeprom[0];
	alarm_minutes = data_from_eeprom[1];
	alarm_status = data_from_eeprom[2];
	while (1){
		Clock_Alarm();
	}
}

