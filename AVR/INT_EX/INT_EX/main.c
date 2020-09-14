/*
 * INT_EX.c
 *
 * Created: 2020-06-15 오후 2:13:25
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP = 0;

SIGNAL(INT4_vect)
{
	cli();
	if(Time_STOP == 0)
	{
		Time_STOP = 1;
	}
	else
	{
		Time_STOP = 0;
	}
	sei();
}

int main(void)
{
	unsigned char LED_Data = 0x01;
	DDRA = 0xFF;
	DDRD = 0x00;
	EICRB = 0x03;
	EIMSK = 0x10;
	EIFR = 0x10;
	sei();
    
    while (1) 
    {
		PORTA = LED_Data;
		if(Time_STOP == 0)
		{
			if(LED_Data == 0x80) LED_Data = 0x01;
			else LED_Data <<= 1;
		}
		_delay_ms(100);
    }
}

