/*
 * Timer.c
 *
 * Created: 2020-06-15 오후 4:47:28
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer0cnt=0;
SIGNAL(TIMER0_OVF_vect);


int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	TCCR0=0x07;//TCCRn에서 CSn0,1,2 : 타이머카운터0에서 1024분주 
	TCNT0=183;//TCNT0레지스터 초기값 설정
	TIMSK=0x01;//비트0,6:타이머카운터0/2 오버플로우 인터럽트
	TIFR |= 1 << TOV0;
	sei();
    while (1) 
    {
		PORTA = LED_Data;
    }
}

SIGNAL(TIMER0_OVF_vect)
{
	cli();
	TCNT0 = 183;
	timer0cnt++;
	if(timer0cnt == 100) //0.01s*100=1s를 얻기 위한 카운트 횟수
	{
		LED_Data++;
		if(LED_Data>0xFF) LED_Data = 0;
		timer0cnt = 0;
	}
	sei();
}

// TCCRn : 제어
// TIMSK : 개별 T/C INT
// TCNT : 타이머카운터 적재 R
// OCR : 비교일치값 적재