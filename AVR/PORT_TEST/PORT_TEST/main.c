/*
 * PORT_TEST.c
 *
 * Created: 2020-06-12 오후 2:10:29
 * Author : PKNU
 */ 

#include <avr/io.h> //io:입출력

int main()
{
	DDRA = 0xFF;	//포트A를 출력으로 설정_방향설정
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRE = 0xFF;
	DDRF = 0xFF;
	DDRG = 0xFF;
	while(1)
	{
		PORTA = 0xFF;	//포트A 0번~7번 핀 5v
		PORTB = 0XFF;
		PORTC = 0XFF;
		PORTD = 0XFF;
		PORTE = 0XFF;
		PORTF = 0XFF;
		PORTG = 0XFF;
	}
	return 0;
}
