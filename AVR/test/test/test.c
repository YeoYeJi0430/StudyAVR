/*
 * test.c
 *
 * Created: 2020-06-18 오전 10:18:29
 * Author : PKNU
 * 여예지
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#define MAX_STR 16

unsigned int doremi[8] = {523,587,659,698,783,880,987,1046};
volatile unsigned char flg=0;
void cds();

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
	unsigned char text[] = "\r\nL : LED\r\nC : CDS\r\n0~7 : PIANO\r\nS : Step Motor\r\npush button : stop";
	unsigned char text2[] = "\n input : ";
	unsigned char i =0;
	unsigned char j;
	//unsigned char x_data = 0;
	unsigned char y_data = 0;
	unsigned char led_data = 0x01; // led
	
	
	DDRE = 0xfe;
	
	//led
	DDRA = 0xFF;	
	
	
	// 음계
	TCCR3A = 0x00; 
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS30);
	TCCR3C = 0x00;
	TCNT3 = 0x0000;
	
	//모터
	DDRB = 0x20;		// 0010 0010	
	DDRD = 0xF0;
	PORTB &= ~0x20;
	
	//인터럽트
	EICRA = 0x03;
	EIMSK = 0x01;
	EIFR = 0x01;
	
	//
	UCSR0A = 0x00;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
	
	UBRR0H = 0X00;
	UBRR0L = 0X03;
	
	
	
	while(text[i]!='\0')
	{
		putch(text[i++]);	
	}
	
		
	sei();
	
    while (1) 
    {
		i=0;
		while(text2[i]!='\0')	putch(text2[i++]);
		y_data = getch();
		putch(y_data);
		
			
		switch(y_data)
		{
			case 'L':
				led_data = 0x01;
				for(i=0;i<7;i++)
				{
					PORTA = led_data;
					led_data <<= 1;
					_delay_ms(1000);
				}
				for(i=0;i<8;i++)
				{
					PORTA = led_data;
					led_data >>= 1;
					_delay_ms(1000);
				}
				break;
			case 'f':
				while(1)
				{
					if(flg==0)
					{
						PORTD = 0x10;
						_delay_ms(10);
						PORTD = 0x20;
						_delay_ms(10);
						PORTD = 0x40;
						_delay_ms(10);
						PORTD = 0x80;
						_delay_ms(10);
					}
					else
					 {
						 flg = 0;
						 break;
					 }
				}
				break;
			case 'r':
				while(1)
				{
					if(flg==0)
					{
					PORTD = 0x80;
					_delay_ms(10);
					PORTD = 0x40;
					_delay_ms(10);
					PORTD = 0x20;
					_delay_ms(10);
					PORTD = 0x10;
					_delay_ms(10);
					}
					else
					{
						flg = 0;
						break;
					}
				}
				break;
			case 'C':
				cds();
				break;
			
			
		}
		
		
		if((y_data >= '0') && (y_data <= '7'))
		{
			PORTC = doremi[y_data - 0x30];
			ICR3 = 7372800/doremi[y_data - 0x30]/2;
			TCCR3A = 0x40;
			_delay_ms(1000);
			TCCR3A = 0x00;
		}
		
    }
	return 0;
}

SIGNAL(INT0_vect)
{
	cli();
	if(flg==0)
	{
		flg = 1;
	}
	sei();
}

void cds()
{
		unsigned int AdData = 0;
		char Cds[MAX_STR];
		int i;
		DDRA = 0XFF;
		DDRF = (1 << DDRF1);   //DDRF1번 출력 나머지 입력 바꿔줌
		ADMUX = 0X00;
		ADCSRA = (1 << ADEN)|(1 << ADPS2)|(1 << ADPS1);      //64분주비
		
		UCSR0A = 0X00;
		UCSR0B = 0X18;
		UCSR0C = 0X06;
		UBRR0H = 0X00;
		UBRR0L = 0X03;
		
		
		sei();
		
		while(1)
		{
			if(flg == 0)
			{
				PORTF = (1 << PORTF1);                  
				ADCSRA |= (1 << ADSC);                  
				
				while((ADCSRA & 0x10)==0x00);            
				AdData = ADC;                        
				
				sprintf(Cds, "Data : %d", AdData);
				i = 0;
				while(Cds[i]!='\0')	putch(Cds[i++]);
				_delay_ms(1000);
			}
			else
			{
				flg = 0;
				break;
			}
		}
}