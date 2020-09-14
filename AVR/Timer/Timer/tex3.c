/*
 * tex3.c
 *
 * Created: 2020-06-16 오전 9:20:58
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0XF3,0X06,0X5B,0X4F,0X66,0X6D,0X7C,
							  0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,
							  0X79,0X71,0X08,0X80};
							  
volatile unsigned char time_s = 0;
unsigned char timer0Cnt = 0;

int main(void)
{
	DDRA = 0xFF;
	
	TCCR0 = 0x07;
	OCR0=71;							//7372800 / 1024 = 7200
										//1/7200 = 1.3888888888888888888888888888889e-4‬
										//1.3888888888888888888888888888889e-4‬ * (OCR0+1) = 0.01
										//OCR0 = 71
	TIMSK=0x02;
	TIFR |=1 << OCF0;
	sei();
	while(1)
	{
		PORTA = FND_DATA_TBL[time_s];
	}
	return 0;
}

SIGNAL(TIMER0_COMP_vect)
{
	cli();
	OCR0 += 71;
	timer0Cnt++;
	
	if(timer0Cnt == 100)
	{
		if(time_s >= 16)
		 time_s = 0;
		else time_s++;
		 timer0Cnt = 0;
	}
	sei();
	
}