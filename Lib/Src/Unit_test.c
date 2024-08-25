#include "Unit_Test.h"
#include "Timer.h"
#include "MCU_Init.h"

#define DELAY_BUTTON 300

uint8_t button_flag_red = 0, button_flag_blue = 0;

void Unit_Test_Led(uint8_t mode){
	switch(mode){
		case 0:
			if(button_flag_blue == 0)
				PORTD |=   (1 << Led_Blue);
			else if(button_flag_blue == 1)
				PORTD &=  ~(1 << Led_Blue);
		break;
		
		case 1:
			if(button_flag_red == 0)
				PORTD |=   (1 << Led_Red);
			else if(button_flag_red == 1)
				PORTD &=  ~(1 << Led_Red);
		break;
		
		case 2:
			PORTD &= ~(1 << Led_Red);
			PORTD |=  (1 << Led_Blue);
			_delay_ms(1000);
			PORTD &= ~(1 << Led_Blue);
			PORTD |=  (1 << Led_Red);
			_delay_ms(1000);
		break;
	}
}

void Unit_Test_Buttons(){
	if(!(PINB & (1 << Button_Ok))){
		_delay_ms(DELAY_BUTTON);
		if(button_flag_blue == 0){
			Unit_Test_Led(0);
			button_flag_blue = 1;
		}
		else if(button_flag_blue == 1){
			Unit_Test_Led(0);
			button_flag_blue = 0;
		}
	}
	if(!(PINB & (1 << Button_Set))){
		_delay_ms(DELAY_BUTTON);
		if(button_flag_red == 0){
			Unit_Test_Led(1);
			button_flag_red = 1;
		}
		else if(button_flag_red == 1){
			Unit_Test_Led(1);
			button_flag_red = 0;
		}
	}
}

