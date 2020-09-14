/*
 * _16tex3.c
 *
 * Created: 2020-06-17 오전 9:16:45
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,0X79,0X71,0X08,0X80};
	
volatile unsigned char time_s=0;					// 초를 세는 변수

int main(void)
{
	DDRA = 0xFF;									// 포트A를 출력 포트 설정
	
	TCCR1A = 0x00;									// 타이머/카운터 1,3 의 동작 설정
	TCCR1B = (1 << CS12) | (1 << CS10);				//프리스케일러 1024
	
	OCR1A = 7200;									// 1초 마다 한번씩 인터럽트 발생
	TIMSK = (1 << OCIE1A);							// TIMSK 비트4 : OCIE1A
	TIFR |=1 << OCF1A;								//출력비교 인터럽트
	
	sei();
	while(1)
	{
		PORTA = FND_DATA_TBL[time_s];
	}
	return 0;
}

SIGNAL(TIMER1_COMPA_vect)
{
	cli();
	
	OCR1A += 7200;									//1초 후에 인터럽트 발생
	if(time_s >= 17)								//17까지만 증가
		time_s = 0;
	else
		time_s++;
		
	sei();
}