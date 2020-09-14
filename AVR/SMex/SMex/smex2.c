/*
 * smex2.c
 *
 * Created: 2020-06-18 오전 9:42:43
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char i;
	
	DDRB = 0x20;
	DDRD = 0xF0;
	PORTB &= ~0x20;
	
	while(1)
	{
		for(i=0;i<12;i++)
		{
			PORTD = 0x30;
			_delay_ms(10);
			PORTD = 0x90;
			_delay_ms(10);
			PORTD = 0xC0;
			_delay_ms(10);
			PORTD = 0x60;
			_delay_ms(10);
		}
		_delay_ms(1000);
	}
}