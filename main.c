/*
 * LCD_Interfacing.c
 *
 * Created: 01-10-2020 00:41:01
 * Author : Ritesh Sharma
 */ 

#include <avr/io.h>
void delay(int);
void send_command(unsigned char);
void send_Data(unsigned char);
void Enable(void);
int main(void)
{
  char a[]="Hello World"
  
  DDRB=0xFF;
  DDRA=0x07;
  PORTA&=~(1<<2);
  int i=0;   
      send_command(0x38);
      delay(10000);
	  send_command(0x0E);
	  delay(10000);
	  send_command(0x01);
	  delay(10000);
	  send_command(0x06);
	  delay(10000);	  
	  while(1)
	  {
		
		  
	  while(a[i]!='\0')
	  {
		  send_Data(a[i]);
		  delay(5000);
		  i++;
	  }
	 
	  
	  }
	  
	  }

void delay(int d)
{
	
	for(int l=0;l<=d;l++);
}
void send_command(unsigned char s)
{
PORTA&=~(1<<0);       /*RS=0*/
PORTB=s;
Enable();
}

void send_Data(unsigned char n)
{
	PORTA|=(1<<0);       /*RS=1*/
	PORTB=n;
	Enable();
	
}
void Enable()
{
	PORTA|=(1<<1);
	delay(10000);
	PORTA&=~(1<<1);
}

	


