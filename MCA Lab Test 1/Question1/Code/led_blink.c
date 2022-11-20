#include "header.h"
#include <lpc214x.h>

int main()
{
    IO0DIR = 0xFFFFFFFF;
	  init_pll();                
	  while(1)
	{
	  IO0SET = 0x00000001;
	  delay_milliseconds(50);
	  IO0CLR = 0x00000001;
		IO0SET = 0x00000002;
	  delay_milliseconds(50);
    IO0CLR = 0x00000002;
		IO0SET = 0x00000004;
	  delay_milliseconds(50);
		IO0CLR = 0x00000004;
		IO0SET = 0x00000008;
		delay_milliseconds(50);
		IO0CLR = 0x00000008;
	}return 0;
}