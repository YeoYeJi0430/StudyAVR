/*
 * lcd.c
 *
 * Created: 2020-06-16 오후 1:51:29
 * Author : PKNU
 */ 

//구구단
//input
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"

int main(void)
{
    Byte str[] = "Iot fighting!!";
	Byte str1[] = "Hi!!";
	DDRA = 0xFF;						// 출력
	LcdInit_4bit();						// lcd초기화함수.h
	
    while (1) 
    {
		Lcd_Pos(0,0);						// lcd위치지정함수.h
		Lcd_STR(str);						// 문자열 출력함수.h
		Lcd_Pos(1,5);
		Lcd_STR(str1);
	}
}

