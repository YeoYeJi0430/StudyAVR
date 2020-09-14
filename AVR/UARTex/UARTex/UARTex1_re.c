/*
 * UARTex1_re.c
 *
 * Created: 2020-06-17 오후 4:13:48
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char TX_flag = 0;
volatile char TX_data = 0; // 스위치 전송 값 저장 변수

void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0); // 전송준비가 될때까지 대기
	UDR0 = data; // 데이터를 UDR0에 쓰면 전송.
	UCSR0A |= 0x20;
}

void putch_Str(char *str)
{
	unsigned char i = 0;
	while(str[i]!='\0')
	putch(str[i++]); // 문자열 출력
}

int main(void)
{
	/* Replace with your application code */
	DDRE = 0x02;
	UCSR0A = 0X00;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Rx, Ex enable
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 비동기 방식, No Parity bit, 1 Stop bit
	UBRR0H = 0X00;
	UBRR0L = 0x03;
	EICRB = 0XFF;
	EIMSK = 0XF0;
	EIFR = 0XF0;
	sei();
	while (1)
	{
		if(TX_flag == 1)
		{
			putch_Str("\n\r Input Switch : ");
			putch(TX_data);
			TX_flag = 0;
		}
	}
}

SIGNAL(INT4_vect)
{
	cli();
	TX_data = '0';
	TX_flag = 1;
	sei();
}

SIGNAL(INT5_vect)
{
	cli();
	TX_data = '1';
	TX_flag = 1;
	sei();
}