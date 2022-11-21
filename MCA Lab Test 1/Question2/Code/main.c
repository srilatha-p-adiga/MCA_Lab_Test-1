#include <lpc214x.h>
#include "header.h"

int main()
{	
	  unsigned char c;
	  int i=0;
	  char string[16];          //char array to store the string recv from UART
	  IO1DIR=0xFFFFFFFF;        //Port 0 is configured as output 
	  init_pll();               //initialise the pll
	  init_uart0();             //initilaise the uart0
	  lcd_init();               //initilaise the lcd
 while(1)
	{ 
		 i=0;                     //count that holds number of characters recieved
		 c=recieve_char_uart0();  //recieve one character
		 while(c!=13 && i<14)     //13 is ascii value for "enter" whenever enter is encountered loop stops 
			{ 
				string[i++]=c;  
				c=recieve_char_uart0();
			}
	  string[i]='\0';                     //make ith element the end of string
		lcd_cmd(0x01);                      //clear screen of lcd
		displayString("STRING RECIEVED:"); //displayString is method to print whole string 
		lcd_cmd(0xC0);                     //got to line 2 of lcd
		displayString(&string[0]);         //print the string recv
		lcd_cmd(0x80);                     //go to line 1
		delay(10);
	 }
     return 0;
}