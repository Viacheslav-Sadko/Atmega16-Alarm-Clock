#include <avr/io.h>
#define F_CPU 8000000UL

/*�������� ������� ��� ������, ������*/

#define Led_Blue PD5
#define Led_Red PD6

void MCU_Init();
void GPIO_Init();