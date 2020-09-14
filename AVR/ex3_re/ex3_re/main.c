/*
 * ex3_re.c
 *
 * Created: 2020-06-15 오전 9:39:17
 * Author : PKNU
 */ 
#define F_CPU 7372800UL //주파수
#include <avr/io.h>
#include <util/delay.h> //delay
//LED char 1

int main(void)
{
    DDRA = 0xFF;
    while (1) 
    {
		PORTA = 0x01;
		_delay_ms(1000);
		PORTA = 0x02;
		_delay_ms(1000);
		PORTA = 0x04;
		_delay_ms(1000);
		PORTA = 0x08;
		_delay_ms(1000);
		PORTA = 16;
		_delay_ms(1000);
		PORTA = 32;
		_delay_ms(1000);
		PORTA = 64;
		_delay_ms(1000);
		PORTA = 128;
		_delay_ms(1000);
    }
}

