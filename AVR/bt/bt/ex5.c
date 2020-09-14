/*
 * ex5.c
 *
 * Created: 2020-06-15 오전 10:21:25
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char Switch_falg = 0, Switch_flag_pre = 0x01;
	
	DDRA = 0x0F;
	DDRE = 0x00;
	PORTA = 0x00;
	
	while(1)
	{
		Switch_falg = PINE >> 4;
		if((Switch_falg == 0x01) || (Switch_falg = 0x02) || (Switch_falg == 0x04) || (Switch_falg == 0x08))
		{
			Switch_flag_pre = Switch_falg;
		}
		PORTA ^= 0x0F;
		if(Switch_flag_pre == 0x01) _delay_ms(250);
		else if(Switch_flag_pre == 0x02) _delay_ms(500);
		else if(Switch_flag_pre == 0x04) _delay_ms(750);
		else if(Switch_flag_pre == 0x08) _delay_ms(1000);
	}
}