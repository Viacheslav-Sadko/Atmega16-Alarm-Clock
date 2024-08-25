#ifndef DS1307_H
#define DS1307_H

#include <stdint.h>

#define DS1307_ADDR 0x68

uint8_t RTC_Bin_To_Dec(uint8_t c);
uint8_t RTC_Dec_To_Bin(uint8_t c);
void DS1307_Set_Time(uint8_t hour, uint8_t minute);
void DS1307_Read_Time();

extern volatile uint8_t time[];

#endif // DS1307_H
