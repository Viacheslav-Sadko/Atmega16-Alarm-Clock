#include <avr/io.h>
#include <avr/interrupt.h>
#include "main.h"

extern volatile uint8_t timer_flag;

ISR(TIMER1_COMPA_vect);
void Timer_Init();