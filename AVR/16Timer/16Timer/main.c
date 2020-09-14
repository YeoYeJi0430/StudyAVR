/*
 * 16Timer.c
 *
 * Created: 2020-06-16 오전 11:21:12
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer1Cnt=0;


int main(void)
{
	DDRA = 0xFF;
	
	TCCR1A = 0x00;
	TCCR1B = (1 << CS10); // 타이머/카운터 제어 레지스터
						  // CSn2:0 (001) => 프리스케일링이 없음
						  
	TCNT1 = 0;
	TIMSK = 
    while (1) 
    {
    }
}

