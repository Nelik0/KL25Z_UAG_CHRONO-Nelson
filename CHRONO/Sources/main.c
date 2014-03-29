#include "derivative.h" /* include peripheral declarations */
#include "lcd.h"
#include "pwm.h"

int seg = 0;
int min = 0;
int centesimas = 0;
int centis = 0;


int main(void)
{
	cfgPortsLCD();
	cfgPortsPWM();
	for(;;)
	{
		if ((TPM0_C1V == 0))
		{
			centis++;
			centesimas = centis * 2;
		}
		if (centis == 50)
		{
			seg++;
			centis = 0;
		}
		if(seg == 60)
		{
			min++;
			seg = 0;
		}
	
		BCD(min);
		sendCode (nIns,0x84);
		sendCode(nData, dec+0x30);
		sendCode(nData, uni+0x30);
		sendCode(nData, ':');
		BCD(seg);
		sendCode(nData, dec+0x30);
		sendCode(nData, uni+0x30);
		sendCode(nData, ':');
		BCD(centesimas);
		sendCode(nData, dec+0x30);
		sendCode(nData, uni+0x30);
	}
}
