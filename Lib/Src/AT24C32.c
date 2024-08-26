#include "AT24C32.h"
#include "I2C.h"
#include "UART.h"

void AT24C32_Write(uint8_t* data_array){
	I2C_Master_Write(AT24C32_ADDR, 0, data_array, 2);
}

void AT24C32_Read(uint8_t* data_array){
	I2C_Master_Read(AT24C32_ADDR, 0, data_array, 3);
}

// 	char buff[7];
// 	AT24C32_Write(&data_to_send);
// 	_delay_ms(1000);
// 	AT24C32_Read(&Data_From_EEPROM);
// 	sprintf(buff, "%02x/%02x/%02x/%02x", Data_From_EEPROM[0], Data_From_EEPROM[1], Data_From_EEPROM[2], Data_From_EEPROM[3]);
// 	UART_Transmit_String(buff);
// 	UART_Transmit(0xd);
// 	UART_Transmit(0xa);
// 	_delay_ms(5000);
