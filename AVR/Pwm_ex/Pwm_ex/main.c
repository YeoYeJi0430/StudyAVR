/*
 * Pwm_ex.c
 *
 * Created: 2020-06-17 오전 11:21:32
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char Light=0;
	
	DDRB = 0x10;
	
	TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << COM00) | (1 << CS02) | (1 << CS01) | (1 << CS02); // WGM:타이머/카운터 동작모드설정(0,1)<-pwm
																								  // WGMn1:WGMn0 = 0:1
																								  // PC PWM 모드 COMn1:COMn0 = 1:1
    while (1) 
    {
		for(Light=0;Light<255;Light++)
		{
			OCR0 = Light;
			_delay_ms(10);
		}
		for(Light=255;0<Light;Light--)
		{
			OCR0 = Light;
			_delay_ms(10);
		}
    }
}

