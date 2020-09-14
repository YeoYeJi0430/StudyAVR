/*
 * bt.c
 *
 * Created: 2020-06-15 오전 10:16:11
 * Author : PKNU
 */ 

#include <avr/io.h>


int main(void)
{
   DDRA = 0xFF;
   DDRE = 0x00;
   while(1)
   {
	   PORTA = PINE;
	   if(PINE == 0x01) PORTA = 0x01;
	   else if(PINE == 0x02) PORTA = 0x02;
	   else if(PINE == 0x04) PORTA = 0x04;
   }
}

