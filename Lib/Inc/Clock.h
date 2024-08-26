#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <avr/io.h>
#include "MCU_Init.h"
#include "Buzzer.h"
#include "I2C.h"
#include "DS1307.h"
#include "AT24C32.h"

uint8_t* Alarm_Get_Current_Value_Ptr();
uint8_t* Get_Current_Value_Ptr();
uint8_t  Get_Current_Value();
uint8_t Alarm_Get_Current_Value();

void Display_Current_Setting(uint8_t mode);
void Display_Time();
void Increase_Value();
void Alarm_Increase_Value();
void Save_Setting(uint8_t mode);
void Enter_Set_Time_Mode();
void Enter_Set_Alarm_Mode();
void Clock_Alarm();
void Alarm_Status();
void Alarm_Check();

extern uint8_t data_from_eeprom[3];
extern uint8_t alarm_hours, alarm_minutes;
extern uint8_t alarm_status;

#endif 
