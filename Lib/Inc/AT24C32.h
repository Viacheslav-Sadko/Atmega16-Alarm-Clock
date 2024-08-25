#include <avr/io.h>

#define AT24C32_ADDR 0x50

unsigned char EE_Read_byte();
int EE_Write_byte(unsigned char c);
void read();
void write();