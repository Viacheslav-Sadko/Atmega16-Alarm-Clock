
#include "AT24C32.h"
#include "I2C.h"
#include "UART.h"

void write(){
	unsigned char arr[] = {0xf, 0xa, 0xc,0xb};
	unsigned int g = 0x1F;
	I2C_Start();
	UART_Transmit(TWSR);
	I2C_Send_byte(0xA0);
	UART_Transmit(TWSR);
	I2C_Send_byte(0x00);
	UART_Transmit(TWSR);
	I2C_Send_byte(0x00);
	UART_Transmit(TWSR);
	for(int i = 0; i < 4; i++){
		//_delay_ms(100);
		EE_Write_byte(arr[i]);
		UART_Transmit(TWSR);
		
	}
	
	I2C_Stop();
}

void read(){
	UART_Transmit(0x0d);
	UART_Transmit(0x0a);
	UART_Transmit(0x0d);
	UART_Transmit(0x0a);
	
	I2C_Start();
	UART_Transmit(TWSR);
	I2C_Send_byte(0xA0);
	UART_Transmit(TWSR);
	I2C_Send_byte(0x00);
	UART_Transmit(TWSR);
	I2C_Send_byte(0x00);
	UART_Transmit(TWSR);
	
	I2C_Start();
	I2C_Send_byte(0xA1);
	unsigned char a;
	for(int i = 0; i < 4; i++){
		a = EE_Read_byte();
		UART_Transmit(a);
	}
	
	I2C_Stop();
}

int EE_Write_byte(unsigned char c){
	TWDR = c;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	if ((TWSR & 0xF8) != TW_MT_DATA_ASK){
		return 1;
	}
	
	return 0;
}

unsigned char EE_Read_byte(){
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWEA);
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}