/*
 * pwmex2.c
 *
 * Created: 2020-06-17 오후 1:44:13
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int DoReMi[8] = {525,587,659,680,783,880,987,1046}; // 피아노 음계에 해당하는 pwm주파수
volatile unsigned char sound_flag = 1;

int main(void)
{
	DDRE = 0x08; // 포트E PE3출력 OC3A
	
	TCCR3A = 0x00; // 타이머/카운터 동작 설정
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS30); // WGM3(3:2)=11, CS3(2:0)=001 1분주사용
	TCCR3C = 0x00;
	
	TCNT3 = 0x0000; // 타이머3 카운터 초기화
	
	EICRA = 0xFF; // 인터럽트 0~3 상승엣지동작설정, D포트(0~3)
	EICRB = 0xFF; // 인터럽트 4~7 상승엣지동작설정, E포트(4~7)
	EIMSK = 0xFF; // 인터럽트 0~7 허용
	EIFR = 0xFF; // 인터럽트 0~7 플래그 클리어
	
	sei();
	while(1)
	{
		if(sound_flag)
		{
			_delay_ms(2000);
			TCCR3A = 0x00;
			sound_flag = 0;
		}
	}
}

SIGNAL(INT0_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[0]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT1_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[1]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT2_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[2]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT3_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[3]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT4_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[4]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT5_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[5]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT6_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[6]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}

SIGNAL(INT7_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[7]/2;
	TCCR3A = 0x40;
	sound_flag = 1;
	sei();
}