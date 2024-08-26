#include <avr/io.h>

#define AT24C32_ADDR 0x50

void AT24C32_Write(uint8_t* data_array);
void AT24C32_Read(uint8_t* data_array);