#include "Buzzer.h"

void Buzzer_Play(){
	sei();
	if(timer_flag == 0)
	PORTA &= ~(1 << Buzzer);
	else if(timer_flag == 1)
	PORTA |=  (1 << Buzzer);
}