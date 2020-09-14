/*
 * UARTswp.c
 *
 * Created: 2020-06-17 오후 4:16:54
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//volatile unsigned char fg = 1;
//volatile char x_data = 0;
unsigned int doremi[8] = {523,587,659,698,783,880,987,1046};
	
void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);
	UDR0 = data;
	UCSR0A |= 0x20;
}

unsigned char getch(void)
{
	unsigned char data;
	while((UCSR0A & 0x80)==0);
	data = UDR0;
	UCSR0A |= 0x80;
	return data;
}

int main(void)
{
	unsigned char y_data = 0;
	DDRE = 0xfe;
	
	UCSR0A = 0x00;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
	
	UBRR0H = 0X00;
	UBRR0L = 0X03;
	
	TCCR3A = 0x00; 
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS30);
	TCCR3C = 0x00;
	
	TCNT3 = 0x0000;
	
	
	
	while(1)
	{
		y_data = getch();
		if((y_data >= '0') && (y_data <= '7'))
		{
			PORTA = doremi[y_data - 0x30];
			ICR3 = 7372800/doremi[y_data - 0x30]/2;
			TCCR3A = 0x40;
			_delay_ms(1000);
			TCCR3A = 0x00;
		}	
		
		
	}
}