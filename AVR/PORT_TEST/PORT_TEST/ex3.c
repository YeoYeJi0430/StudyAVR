/*
 * ex3.c
 *
 * Created: 2020-06-12 오후 4:43:28
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char LED_Data = 0x01, i;
	DDRA = 0xFF;
	while(1)
	{
		LED_Data = 0x01;
		
		for(i=0; i<7; i++)
		{
			PORTA = LED_Data;
			LED_Data <<= 1; //비트이동
			_delay_ms(1000);
		}
		
		for(i=0; i<7; i++)
		{
			PORTA = LED_Data;
			LED_Data >>= 1;
			_delay_ms(1000);
		}
	}
}