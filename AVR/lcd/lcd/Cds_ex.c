/*
 * Cds_ex.c
 *
 * Created: 2020-06-16 오후 4:56:52
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"

int main(void)
{
	unsigned int AdData = 0;
	
	Byte str[20];
	DDRF = (1 << DDRF1);
	ADMUX = 0x00;
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	LcdInit_4bit();
	
	while(1)
	{
		ADCSRA |= 0x40;
		while((ADCSRA & 0x10) == 0x00);
		AdData = ADC;
		Lcd_Pos(0,0);
		
		Lcd_STR(" Cds: ");
		Lcd_CHAR((AdData/1000)%10 + '0');
		Lcd_CHAR((AdData/100)%10 + '0');
		Lcd_CHAR((AdData/10)%10 + '0');
		Lcd_CHAR((AdData)%10 + '0');
		_delay_ms(500);
	}
}