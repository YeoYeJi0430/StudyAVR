﻿/*
 * ex7.c
 *
 * Created: 2020-06-15 오전 11:17:44
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int Count_TR(unsigned char flag);

int main(void)
{
	unsigned char FND_DATA_TBL []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,
								   0x7C,0x07,0x7F,0x67,0x77,0x7C,
								   0x39,0x5E,0x79,0x71,0x08,0x80};
	
	unsigned int cnt = 0;
	unsigned char Switch_flag = 0;
	
	DDRA = 0xFF;
	DDRD = 0x00;
	while(1)
	{
		Switch_flag = PIND; //>> 4;
		while(PIND != 0x00);
		
		if(Switch_flag !=0x00) 
			cnt += Count_TR(Switch_flag);
			
		if(cnt<0)
			cnt = 0;
		else if(cnt > 15)
			cnt = 15;
			
		PORTA = FND_DATA_TBL[cnt];
		_delay_ms(100);
	}
}

int Count_TR(unsigned char flag)
{
	int count = 0;
	switch (flag)
	{
		case 0x01: 
			count = 1;
			break;
		case 0x02: 
			count = 2;
			break;
		case 0x04:
			count = 3;
			break;
		case 0x08:
			count = 4;
			break;
		case 0x10:
			count = -1;
			break;
		case 0x20:
			count = -2;
			break;
		case 0x40:
			count = -3;
			break;
		case 0x80:
			count = -4;
			break;
	}
	return count;
}