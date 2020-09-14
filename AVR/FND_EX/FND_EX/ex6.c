﻿/*
 * ex6.c
 *
 * Created: 2020-06-15 오전 11:09:00
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char FND_DATA_TBL [] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71,0x08,0x80};
		
	unsigned char cnt = 0;
	DDRA = 0xFF;
	while(1)
	{
		PORTA = FND_DATA_TBL[cnt];
		cnt++;
		if(cnt>17) cnt = 0;
		_delay_ms(2000);
	}
}