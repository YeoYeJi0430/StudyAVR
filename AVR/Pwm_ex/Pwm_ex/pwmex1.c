/*
 * pwmex1.c
 *
 * Created: 2020-06-17 오전 11:40:36
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int light = 0;
volatile unsigned char light_flag = 1;

int main(void)
{
	DDRB = 0x80;
	DDRE = 0x00;
	
	TCCR2 = 0x62;//(1 << WGM20) | (1 << COM21) | (1 << CS21);
	TCNT2 = 0x00;
	
	//EICRA = 0xFF;
	EICRA = 0xFF;		//외부 인터럽트 0~3의 트리거 설정에 사용 D포트
	EICRB = 0xFF;		//외부 인터럽트 4~7의 트리거 설정에 사용 E포트
	EIMSK = 0xFF;		//인터럽트 4,5,6,7 허용
	EIFR = 0xFF;		//인터럽트 4,5,6,7, 플래그 클리어
	
	sei();
	
	while(1)
	{
		if(light_flag)
		{
			OCR2 = light;
			light_flag = 0;
		}
	}
}

SIGNAL(INT0_vect)
{
	cli();
	light = 0;
	light_flag = 1;
	sei();
}

SIGNAL(INT1_vect)
{
	cli();
	light -= 20;
	if(light<0)
		light=0;
	light_flag = 1;
	sei();
}

SIGNAL(INT2_vect)
{
	cli();
	light -= 30;
	if(light<0)
	light=0;
	light_flag = 1;
	sei();
}

SIGNAL(INT3_vect)
{
	cli();
	light -= 40;
	if(light<0)
	light=0;
	light_flag = 1;
	sei();
}

SIGNAL(INT4_vect)
{
	cli();
	light += 10;
	if(light>255)
		light = 255;
	light_flag = 1;
	sei();
	
}

SIGNAL(INT5_vect)
{
	cli();
	light += 20;
	if(light>255)
		light = 255;
	light_flag = 1;
	sei();
}

SIGNAL(INT6_vect)
{
	cli();
	light += 30;
	if(light>255)
		light = 255;
	light_flag = 1;
	sei();
}

SIGNAL(INT7_vect)
{
	cli();
	light = 255;
	light_flag = 1;
	sei();
}