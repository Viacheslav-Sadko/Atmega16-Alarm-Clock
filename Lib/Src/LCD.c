#include "LCD.h"

void LCD_Init(){
	_delay_ms(15);
	LCD_Send_Half_Byte(0x3);
	_delay_ms(4);
	LCD_Send_Half_Byte(0x3);
	_delay_ms(100);
	LCD_Send_Half_Byte(0x3);
	_delay_ms(1);
	LCD_Send_Half_Byte(0x2);
	_delay_ms(1);
	LCD_Send_Byte(0x28, 0);
	_delay_ms(1);
	LCD_Send_Byte(0xC, 0); 
	_delay_ms(1);
	LCD_Send_Byte(0x6, 0); 
	_delay_ms(1);
}
void LCD_Send_Half_Byte(uint8_t half_byte) {
	_delay_us(50);
	half_byte = (half_byte << 2) & 0x3C;
	Enable_1;
	PORTC &= 0xC3;
	PORTC |= half_byte;
	Enable_0;
	_delay_us(50);
}

void LCD_Send_Byte(uint8_t byte, uint8_t mode) {
	if (mode == 0) RS_0;
	else RS_1;

	uint8_t half_byte_high = (byte >> 4) & 0x0F;
	uint8_t half_byte_low = byte & 0x0F;
	LCD_Send_Half_Byte(half_byte_high);
	LCD_Send_Half_Byte(half_byte_low);
}

void LCD_Send_Char(uint8_t byte){
	LCD_Send_Byte(byte, 1);
}
void LCD_Set_Cursor(uint8_t horizontal, uint8_t vertical){
	uint8_t position = 0;
	position = (0x40 * vertical + horizontal)|0x80;
	LCD_Send_Byte(position, 0);
}
void LCD_Clear(){
	LCD_Send_Byte(0x1, 0);
	_delay_us(1500);
}

void LCD_String(char* message){
	for(int i = 0; message[i] != '\0'; i++){
		LCD_Send_Char(message[i]);
	}
}