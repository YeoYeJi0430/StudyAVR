/*
 * ex1.c
 *
 * Created: 2020-06-12 오후 3:52:15
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	while(1)
	{
		DDRA = 0x03;
		
		PORTA = 0x0F;
		_delay_ms(500);
		
		PORTA = 0x00;
		_delay_ms(500);
		
		
		
		DDRA = 0x0C;
		
		PORTA = 0x0F;
		_delay_ms(500);
		
		PORTA = 0x00;
		_delay_ms(500);
	}
}