/*
 * tex.c
 *
 * Created: 2020-06-16 오전 10:21:26
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,
							  0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,
							  0X79,0X71,0X08,0X80};
							  
volatile unsigned char time_s = 0;
volatile unsigned char Time_STOP = 0;

unsigned char timer0Cnt = 0;

int main(void)
{
	DDRA = 0xFF;				// 포트A 출력포트 설정
	DDRE = 0x00;				// 포트E 입력포트 설정
	TCCR2 = (1 << CS22);	// 프리스케일러 1024, 일반모드
	OCR2 = 72;					// 비교일치 R2에 72값저장
	TIMSK = (1 << OCIE2);		//타이머카운터2 비교일치인터럽트 인에이블
	TIFR |= (1 << OCF2);		//타이머카운터2 비교일치 플래그 리셋
	
	EICRB = 0x03;
	EIMSK = 0x10;
	EIFR = 0x10;
	
	sei();
	
	while(1)
	{
		PORTA = FND_DATA_TBL[time_s];
	}
	return 0;
}

SIGNAL(TIMER2_COMP_vect)
{
	cli();
	OCR2 += 72;
	timer0Cnt++;
	if(timer0Cnt == 50)
	{
		if(Time_STOP == 0)
		{
			if(time_s >= 16)
				time_s = 0;
			else
				time_s++;
		}
		timer0Cnt = 0;
	}
	sei();
}

SIGNAL(INT4_vect)
{
	cli();
	
	if(Time_STOP == 0)
		Time_STOP = 1;
	else
		Time_STOP = 0;
		
	sei();
}