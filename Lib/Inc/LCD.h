#include <avr/io.h>
#include <util/delay.h>
#include "stdint.h"
#include "main.h"

#define Data_0   PC2
#define Data_1   PC3
#define Data_2   PC4
#define Data_3   PC5
#define Enable   PC6
#define RS       PC7

#define Enable_0 PORTC &= ~(1 << PC6)
#define Enable_1 PORTC |=  (1 << PC6)
#define RS_0     PORTC &= ~(1 << PC7)
#define RS_1     PORTC |=  (1 << PC7)

void LCD_Init();
void LCD_Send_Half_Byte(uint8_t half_byte);
void LCD_Send_Byte(uint8_t byte, uint8_t mode);
void LCD_Set_Cursor(uint8_t horizontal, uint8_t vertical);
void LCD_Send_Char(uint8_t byte);
void LCD_String(char* message);
void LCD_Clear();