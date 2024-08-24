#include "Timer.h"
volatile uint8_t timer_flag = 0;
ISR(TIMER1_COMPA_vect){
	if(timer_flag == 0)
		timer_flag = 1;
	else if(timer_flag == 1)
		timer_flag = 0;
}

void Timer_Init(){
	TCCR1B |= (1 << WGM12);
	TIMSK  |= (1 << OCIE1A);
	OCR1AH = 0x00;
	OCR1AL = 0xFF;
	TCCR1B |= (1 << CS12);
}