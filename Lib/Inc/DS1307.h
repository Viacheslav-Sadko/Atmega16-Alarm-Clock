#include <avr/io.h>
#include <util/delay.h>

#define RTC_addr_w 0b11010000
#define RTC_addr_r 0b11010001

void RTC_write();
unsigned char RTC_dec_bin(unsigned char c);
unsigned char RTC_bin_dec(unsigned char c);
