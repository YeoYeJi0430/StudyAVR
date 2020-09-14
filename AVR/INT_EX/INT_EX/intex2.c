/*
 * intex2.c
 *
 * Created: 2020-06-15 오후 3:02:35
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Shift_flag = 1;



int main(void)
{
	unsigned char LED_Data = 0x01;
	
	DDRA = 0xFF;
	DDRE = 0x00;
	DDRD = 0x00;
	
	EICRB = 0x02; //4를 하강
	EICRA = 0x03;
	
	EIMSK = 0x11;
	EIFR = 0x11;
	
	sei();
	
	while(1)
	{
		PORTA = LED_Data;
		if(Shift_flag == 1) 
		{
			if(LED_Data == 0x80) LED_Data = 0x01;
			else LED_Data <<= 1;
		}
		else if(Shift_flag == 2)
		{
			if(LED_Data == 0x01) LED_Data = 0x80;
			else LED_Data >>= 1;
		}
		_delay_ms(100);
	}
}

SIGNAL(INT4_vect)
{
	cli();
	Shift_flag = 1;
	sei();
}

SIGNAL(INT0_vect)
{
	cli();
	Shift_flag = 2;
	sei();
}