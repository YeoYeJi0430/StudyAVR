/*
 * _99.c
 *
 * Created: 2020-06-16 오후 2:41:40
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Lcd.h"
//sf
char sf(char Switch_flag);
int main(void)
{
	unsigned char Switch_flag = 0;
	Byte str1[] = "99";
	Byte str2[] = "Input";
	Byte num[100];
	DDRA = 0xFF;
	DDRD = 0x00;
	
	
	LcdInit_4bit();
	
	Lcd_Pos(0,0);
	Lcd_STR(str1);
	Lcd_Pos(1,0);
	Lcd_STR(str2);
	
	while(1)
	{
		Switch_flag = PIND;
		if(Switch_flag == 0x01)
		{
			Lcd_Clear();
			for(int i=1;i<10;i++)
			{
				sprintf(num,"%d",2*i);
				Lcd_Pos(0,0);
				Lcd_STR(num);
				_delay_ms(500);
			}
		}
		else if(Switch_flag == 0x02)
		{
			Lcd_Clear();
			for(int i=1;i<10;i++)
			{
				sprintf(num,"%d",3*i);
				Lcd_Pos(0,0);
				Lcd_STR(num);
				_delay_ms(500);
			}
		}
	}	
}

char sf(char Switch_flag)
{
	if(Switch_flag == 0x01) return 2;
	else if(Switch_flag == 0x02) return 3;
	else if(Switch_flag == 0x04) return 4;	
}