/*
 * _16tex4.c
 *
 * Created: 2020-06-17 오전 9:57:40
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char FND_DATA_TBL[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,0X79,0X71,0X08,0X80};
volatile unsigned char time_s=0;									//초를 세는 변수
volatile unsigned char FND_flag=0, edge_flag=0;

int main(void)
{
	DDRA = 0xFF;
	DDRE = 0x00;
	
	TCCR3A = 0x00;
	TCCR3B = (1 << ICES3) | (1 << CS32) | (1 << CS30);				//프리스케일러 1024, 상승 에지 캡처 트리거 설정
																	//ICESn : ICn에 해당되는 에지의 형태 선택
	ETIMSK = 0x20;
	ETIFR |=1 << ICF3;												//Input Capture Flag 3
	
	sei();
	PORTA = FND_DATA_TBL[0];										//PORTA에 FND Table 값 출력
	while(1)
	{
		if(FND_flag)
		{
			if(time_s > 15)											//최대 1.5초까지 표시
				time_s = 15;
				
			PORTA = FND_DATA_TBL[time_s];							//포트A에 FND Table 값 출력
			FND_flag = 0;
		}
	}
	return 0;
}

SIGNAL(TIMER3_CAPT_vect)
{
	cli();
	unsigned int count_check;
	
	if(edge_flag == 0)												//상승 에지(스위치 누르면)
	{
		TCCR3B = (1 << CS32) | (1 << CS30);							//프리스케일러 1024, 하강 에지
		TCNT3 = 0;
		ICR3 = 0;
		edge_flag = 1;
	}
	
	else
	{
		TCCR3B = (1 << ICES3) | (1 << CS32) | (1 << CS30);
		count_check = ICR3;
		
		time_s = count_check/720;
		
		FND_flag = 1;
		edge_flag = 0;
	}
	sei();
	
}