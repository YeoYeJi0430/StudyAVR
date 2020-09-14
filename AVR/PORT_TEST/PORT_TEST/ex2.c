/*
 * ex2.c
 *
 * Created: 2020-06-12 오후 4:23:15
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char LED_Data = 0x00;
	DDRA = 0x0F;
	while(1)
	{
		PORTA = LED_Data;
		LED_Data++;
		
		if(LED_Data > 0x0F) LED_Data = 0;
		_delay_ms(1000);
	}
}