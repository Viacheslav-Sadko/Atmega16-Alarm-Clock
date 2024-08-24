#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

void I2C_init(){
	TWBR = 0x40;
}

void I2C_Start(){
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);
	while( !(TWCR & (1 << TWINT)) );
}

void I2C_Stop(){
	TWCR = (1 << TWINT)|(1 << TWSTO)|(1 << TWEN);
}

void I2C_Send_byte(unsigned char c){
	TWDR = c;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
}

unsigned char I2C_Read_byte(void){
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWEA);
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}

unsigned char I2C_ReadLastByte(void){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}