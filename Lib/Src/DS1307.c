#include "DS1307.h"

volatile uint8_t time[3] = {0};

uint8_t RTC_Bin_To_Dec(uint8_t c){
	uint8_t res = ((c >> 4) * 10) + (c & 0x0F);
	return res;
}

uint8_t RTC_Dec_To_Bin(uint8_t c){
	uint8_t res = ((c / 10) << 4) | (c % 10);
	return res;
}

void DS1307_Set_Time(uint8_t hour, uint8_t minute){
	I2C_Start();
	I2C_Send_Byte((DS1307_ADDR << 1) & 0xFE);  // Write address
	I2C_Send_Byte(0x00);  // Start address for time
	I2C_Send_Byte(0);
	I2C_Send_Byte(RTC_Dec_To_Bin(minute));
	I2C_Send_Byte(RTC_Dec_To_Bin(hour));
	I2C_Stop();
}

void DS1307_Read_Time(){
	I2C_Start();
	I2C_Send_Byte((DS1307_ADDR << 1) & 0xFE);  // Write address
	I2C_Send_Byte(0x00);  // Start address for time
	I2C_Start();
	I2C_Send_Byte((DS1307_ADDR << 1) | 0x01);  // Read address
	time[0] = I2C_Read_Byte();
	time[1] = I2C_Read_Byte();
	time[2] = I2C_Read_Last_Byte();
	I2C_Stop();
	time[0] = RTC_Bin_To_Dec(time[0]);
	time[1] = RTC_Bin_To_Dec(time[1]);
	time[2] = RTC_Bin_To_Dec(time[2]);
}
