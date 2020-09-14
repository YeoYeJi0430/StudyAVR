/*
 * bt.c
 *
 * Created: 2020-06-15 오전 10:09:07
 *  Author: PKNU
 */ 
#include <avr/io.h>

int main()
{
	unsigned char Switch_flag = 0,
	DDRA = 0xFF;
	DDRD = 0x00;
	
	while(1)
	{
		if(PIND == 0x01) PORTA = 0x01;
		else if(PIND == 0x02) PORTA = 0x02;
		else if(PIND == 0x04) PORTA = 0x04;
	}
}