/*
 * SMex.c
 *
 * Created: 2020-06-18 오전 9:32:28
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DDRB = 0x20;
	DDRD = 0xF0;
	PORTB &= ~0x20;
	while (1) 
    {
		PORTD = 0x10;
		_delay_ms(10);
		PORTD = 0x20;
		_delay_ms(10);
		PORTD = 0x30;
		_delay_ms(10);
		PORTD = 0x40;
		_delay_ms(10);
		PORTD = 0x80;
		_delay_ms(10);
    }
}

