/*
 * tex2.c
 *
 * Created: 2020-06-15 오후 5:07:03
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x01;
unsigned char timer2Cnt=0, Shif_Flag=0;

SIGNAL(TIMER2_OVF_vect);

int main(void)
{
	DDRA = 0xFF;
	
	TCCR2 = 0x05;//TCCRn 타이머/카운터2 : 101(1024분주)
	
	TCNT2 = 183; //타이머카운터 적재 R
	TIMSK=0x40;//TIMSK : TOIE2
	TIFR |=1 << TOV2;
	sei();
	
	while(1)
	{
		PORTA = LED_Data;
	}
	return 0;
}

SIGNAL(TIMER2_OVF_vect)
{
	cli();
	TCNT2 = 183;
	timer2Cnt++;
	if(timer2Cnt == 50)
	{
		if(Shif_Flag==0)
		{
			LED_Data <<= 1;
			if(LED_Data == 0x80) Shif_Flag = 1;
		}
		else
		{
			LED_Data >>= 1;
			if(LED_Data == 0x01) Shif_Flag = 0;
		}
		timer2Cnt=0;
	}
	sei();
}