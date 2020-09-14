/*
 * intex4.c
 *
 * Created: 2020-06-15 오후 3:47:12
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char Time_STOP = 0;
volatile unsigned char cnt = 0;

SIGNAL(INT0_vect)
{
	cli();
	
	Time_STOP = 1;
	cnt = 0;
	
	sei();
}

SIGNAL(INT3_vect)
{
	cli();
	Time_STOP=0;
	sei();
}

int main(void)
{
	unsigned char FND_DATA_TBL[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,
								  0X7C,0X07,0X7F,0X67,0X77,0X7C,
								  0X39,0X5E,0X79,0X71,0X08,0X80};
								  
	DDRA = 0xFF;
	DDRD = 0x00;
	
	EICRA = 0xC2;
	//EICRA = 0xC0;
	EIMSK = 0x09;
	EIFR = 0x09;
	sei();
	
	while(1)
	{
		PORTA = FND_DATA_TBL[cnt];
		if(Time_STOP == 0)
		{
			cnt++;
			if(cnt>17) cnt=0;
		}
		_delay_ms(200);
	}
}