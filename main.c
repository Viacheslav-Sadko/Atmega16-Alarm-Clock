#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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

uint8_t flag_set = 0;

typedef enum {
	MODE_NORMAL,
	MODE_MENU,
	MODE_SET_TIME,
	MODE_SET_ALARM,
	MODE_ALARM_SETTINGS
} Mode;

Mode Current_Mode = MODE_NORMAL;

void Display_Time(){
	
	LCD_Set_Cursor(0, 0);
	LCD_String("Time:     Alarm:");
}
void Enter_Set_Time_Mode(){
	
}
void Clock_Alarm(){
	
	if (Current_Mode == MODE_NORMAL) {
		
		Display_Time();
	}
	if(!(PINB & (1 << Button_Ok))){
		_delay_ms(250);
		switch(Current_Mode){
			case MODE_NORMAL:
				Current_Mode = MODE_MENU;
				flag_set = 0;
				LCD_Clear();
				LCD_Set_Cursor(0, 0);
				LCD_String("* Set time");
				LCD_Set_Cursor(0, 1);
				LCD_String("  Set alarm");
			break;
			
			case MODE_MENU:
				if (flag_set == 0) {
					LCD_Clear();
					LCD_Set_Cursor(0, 0);
					LCD_String("  Set time");
					LCD_Set_Cursor(0, 1);
					LCD_String("* Set alarm");
					flag_set = 1;
					} else {
					LCD_Clear();
					LCD_Set_Cursor(0, 0);
					LCD_String("* Set time");
					LCD_Set_Cursor(0, 1);
					LCD_String("  Set alarm");
					flag_set = 0;
				}
			break;
		}
	}
	if(!(PINB & (1 << Button_Set))){
		_delay_ms(250);
		if (flag_set == 0) {
			Enter_Set_Time_Mode();
			LCD_Clear();
			Current_Mode = MODE_NORMAL;
			} else {
			Enter_Set_Time_Mode();
			LCD_Clear();
			Current_Mode = MODE_NORMAL;
		}
	}
}

int main(void){
	
	MCU_Init();
	//sei();
	LCD_Clear();
	LCD_String("Alarm");
	while (1){
		Clock_Alarm();
	}
}

