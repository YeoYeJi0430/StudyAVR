/*
 * FND_EX.c
 *
 * Created: 2020-06-15 오전 11:04:05
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTA = 0b00111111; // 0b=00111111 : 0 : 0x3f
		_delay_ms(1000);
		PORTA = 0b00000110;
		_delay_ms(1000);
    }
}

