#include "Clock.h"

uint8_t flag_set = 0;

typedef enum {
	MODE_NORMAL,
	MODE_MENU,
	MODE_SET_TIME,
	MODE_SET_ALARM,
	MODE_ALARM_SETTINGS
} Mode;

Mode Current_Mode = MODE_NORMAL;

uint8_t selected_parameter = 0;
uint8_t hours = 2, minutes = 25, seconds = 0, day = 13, month = 8, year = 24; // Значення часу і дати
uint8_t latest_get_current_value = 100;
uint8_t alarm_hours = 0, alarm_minutes = 0;

const uint8_t max_values[] = {23, 59, 59, 31, 12, 99};

uint8_t* Alarm_Get_Current_Value_Ptr(){
	switch (selected_parameter) {
		case 0: return &alarm_hours;
		case 1: return &alarm_minutes;
		default: return &alarm_hours;
	}
}

uint8_t* Get_Current_Value_Ptr(){
	switch (selected_parameter) {
		case 0: return &hours;
		case 1: return &minutes;
		default: return &hours;
	}
}


uint8_t  Get_Current_Value(){
	switch (selected_parameter) {
		case 0: return hours;
		case 1: return minutes;
		default: return 0;
	}
}

uint8_t Alarm_Get_Current_Value(){
	switch (selected_parameter) {
		case 0: return alarm_hours;
		case 1: return alarm_minutes;
		default: return 0;
	}
}

void Display_Current_Setting(uint8_t mode){
	char value_string[3];
	switch(mode){
		case 0:
		if(Get_Current_Value() != latest_get_current_value){
			latest_get_current_value = Get_Current_Value();
			LCD_Clear();
			LCD_Set_Cursor(0, 0);
			LCD_String("Set ");
			switch(selected_parameter){
				case 0:
				LCD_String("Hours: ");
				break;
				case 1:
				LCD_String("Minutes: ");
				break;
			}
			sprintf(value_string, "%02d", Get_Current_Value());
			LCD_Set_Cursor(0, 1);
			LCD_String(value_string);
		}
		break;
		case 1:
		if(Alarm_Get_Current_Value() != latest_get_current_value){
			latest_get_current_value = Alarm_Get_Current_Value();
			LCD_Clear();
			LCD_Set_Cursor(0, 0);
			LCD_String("Set ");
			switch(selected_parameter){
				case 0:
				LCD_String("Hours: ");
				break;
				case 1:
				LCD_String("Minutes: ");
				break;
			}
			sprintf(value_string, "%02d", Alarm_Get_Current_Value());
			LCD_Set_Cursor(0, 1);
			LCD_String(value_string);
		}
		break;
	}
}

void Display_Time(){
	
	LCD_Set_Cursor(0, 0);
	LCD_String("Time:     Alarm:");
}

void Increase_Value(){
	uint8_t *value_ptr = Get_Current_Value_Ptr();
	(*value_ptr)++;

	if (*value_ptr > max_values[selected_parameter]) {
		*value_ptr = 0;
	}
}

void Alarm_Increase_Value(){
	uint8_t *value_ptr = Alarm_Get_Current_Value_Ptr();
	(*value_ptr)++;

	if (*value_ptr > max_values[selected_parameter]) {
		*value_ptr = 0;
	}
}


void Save_Setting(){
	
}
void Enter_Set_Time_Mode(){
	LCD_Clear();
	LCD_Set_Cursor(0, 0);
	LCD_String("Set time");
	
	while(1){
		Display_Current_Setting(0);
		if(!(PINB & (1 << Button_Ok))){
			_delay_ms(250);
			Increase_Value();
		}
		if(!(PINB & (1 << Button_Set))){
			_delay_ms(250);
			selected_parameter++;
			if(selected_parameter > 1){
				selected_parameter = 0;
				Save_Setting(1);
				break;
			}
		}
		
	}
}

void Enter_Set_Alarm_Mode(){
	LCD_Clear();
	LCD_Set_Cursor(0, 0);
	LCD_String("Set alarm:");
	
	while(1){
		Display_Current_Setting(1);
		if(!(PINB & (1 << Button_Ok))){
			_delay_ms(250);
			Alarm_Increase_Value();
		}
		if(!(PINB & (1 << Button_Set))){
			_delay_ms(250);
			selected_parameter++;
			if(selected_parameter > 1){
				selected_parameter = 0;
				Save_Setting(0);
				break;
			}
		}
		
	}
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
			case MODE_SET_TIME:
			Enter_Set_Time_Mode();
			Current_Mode = MODE_NORMAL;
			break;

			case MODE_SET_ALARM:
			Enter_Set_Alarm_Mode();
			Current_Mode = MODE_NORMAL;
			break;
		}
	}
	if(!(PINB & (1 << Button_Set)) && Current_Mode == MODE_MENU){
		_delay_ms(250);
		if (flag_set == 0) {
			Enter_Set_Time_Mode();
			LCD_Clear();
			Current_Mode = MODE_NORMAL;
			} else {
			Enter_Set_Alarm_Mode();
			LCD_Clear();
			Current_Mode = MODE_NORMAL;
		}
	}
}