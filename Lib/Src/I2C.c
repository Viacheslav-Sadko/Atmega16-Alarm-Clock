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

uint8_t I2C_Send_Byte(uint8_t c) {
	TWDR = c; 
	TWCR = (1 << TWINT) | (1 << TWEN); 
	while (!(TWCR & (1 << TWINT))); 
	
	return (TWSR & 0xF8); 
}

uint8_t I2C_Read_Byte(){
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWEA);
	while(!(TWCR & (1 << TWINT)));
	return TWDR;
}

unsigned char I2C_Read_Last_Byte(){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}

void I2C_Master_Write(uint8_t slave_address, uint16_t memory_stacker, uint8_t* pData, uint8_t size){
	I2C_Start();
	I2C_Send_Byte((slave_address << 1) & 0xFE);
	I2C_Send_Byte(memory_stacker >> 8);
	I2C_Send_Byte(memory_stacker);
	for(uint8_t i = 0; i < size; i++){
		_delay_us(I2C_DELAY);
		I2C_Send_Byte(pData[i]);
	}
	I2C_Stop();
}

void I2C_Master_Read(uint8_t slave_address, uint16_t memory_stacker, uint8_t* pData, uint8_t size){
	I2C_Start();
	I2C_Send_Byte((slave_address << 1) & 0xFE);  // Передаємо адресу пристрою з бітами запису
	I2C_Send_Byte(memory_stacker >> 8);          // Старший байт адреси комірки пам'яті
	I2C_Send_Byte(memory_stacker);               // Молодший байт адреси комірки пам'яті
	
	I2C_Start(); // Перезапуск для читання
	I2C_Send_Byte((slave_address << 1) | 0x01);  // Передаємо адресу пристрою з бітами читання

	for(uint8_t i = 0; i < size; i++){
		_delay_us(I2C_DELAY); // Затримка
		if (i < (size - 1)) {
			pData[i] = I2C_Read_Byte(1); // Читаємо байт даних, ACK для всіх крім останнього байта
			} else {
			pData[i] = I2C_Read_Last_Byte(); // Читаємо останній байт, NACK
		}
	}
	I2C_Stop();
}



void I2C_Scanner() {
	char buff[30];
	UART_Transmit_String("Scanning I2C bus...\n");
	for (uint8_t address = 1; address < 128; address++) {
		I2C_Start();
		uint8_t status = I2C_Send_Byte(address << 1);
		if (status == 0x18) {
			sprintf(buff, "Device found at 0x%02X\n", address);
			UART_Transmit_String(buff);
		}
		I2C_Stop();
	}
	UART_Transmit_String("Scan completed.\n");
}