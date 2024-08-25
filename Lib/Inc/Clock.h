#include <avr/io.h>
#include "MCU_Init.h"
#include "stdint.h"

uint8_t* Alarm_Get_Current_Value_Ptr();
uint8_t* Get_Current_Value_Ptr();
uint8_t  Get_Current_Value();
uint8_t Alarm_Get_Current_Value();
void Display_Current_Setting(uint8_t mode);
void Display_Time();
void Increase_Value();
void Alarm_Increase_Value();
void Save_Setting();
void Enter_Set_Time_Mode();
void Enter_Set_Alarm_Mode();
void Clock_Alarm();