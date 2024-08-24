#include "DS1307.h"

unsigned char sec, min, hour, day, date, month, year;

unsigned char RTC_bin_dec(unsigned char c){
	unsigned char res = ((c/10) << 4)|(c % 10);
	return res;
}

unsigned char RTC_dec_bin(unsigned char c){
	unsigned char res = ((c >> 4)*10 + (0b00001111 & c));
	return res;
}

void RTC_write(){
	I2C_Start();
	I2C_Send_byte(RTC_addr_w);
	I2C_Send_byte(0);
	I2C_Send_byte(RTC_bin_dec(50)); //sec
	I2C_Send_byte(RTC_bin_dec(53)); //min
	I2C_Send_byte(RTC_bin_dec(20)); //hour
	I2C_Send_byte(RTC_bin_dec(4)); //huyna
	I2C_Send_byte(RTC_bin_dec(28)); //day
	I2C_Send_byte(RTC_bin_dec(5)); //month
	I2C_Send_byte(RTC_bin_dec(24)); //year
	I2C_Stop();
}