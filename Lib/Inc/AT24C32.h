#include <avr/io.h>

#define EE_adrr 0xA0
#define TW_MT_DATA_ASK 0x28

unsigned char EE_Read_byte();
int EE_Write_byte(unsigned char c);
void read();
void write();