#include "header.h"
#include <lpc214x.h>

void delay_milliseconds(unsigned int milliseconds)
{
   T0CTCR = 0x0;  //Select the timer mode
	 T0TCR = 0x00;  //Timer off
	 T0PR = 59999;  //Prescale value
	 T0TCR = 0x02;  //Timer reset
	 T0TCR = 0x01;  // Timer on
	 while(T0TC < milliseconds); //Check for the count of time
	 T0TCR = 0x00;     //Timer off
	 T0TC = 0;        // Clear the TC
}

void init_pll()
{
  PLL0CON = 0x01;
  PLL0CFG = 0x24;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  while(!(PLL0STAT & (1<<10)));
  PLL0CON = 0x03;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
	VPBDIV = 0x01;
}