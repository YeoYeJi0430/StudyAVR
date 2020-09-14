/*
 * smex3.c
 *
 * Created: 2020-06-18 오전 10:05:03
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <util/delay.h>

unsigned char step[8] = {0x90,0x80,0xc0,0x40,0x60,0x20,0x30,0x10};
	
int main(void)
{
	unsigned char i,t=0;
	
	DDRB = 0x20;
	DDRD = 0xF0;
	PORTB &= ~0x20;
	
	while(1)
	{
		// 명령당 3.75도 회전, 90도 회전하려면 총 24개의 명령이 필요
		for(i=0;i<24;i++)
		{
			PORTD = step[t];	// 한 스텝 실행
			t++;				// 다음 스텝 실행을 위해 t증가
			if(t>7) t=0;		// 8스텝을 초과하지 않도록 초기화 , 3번 회전
			_delay_ms(10);
		}
		_delay_ms(1000);
	}
}