#include "glcd.h"
#include "gpio.h"
#include<LPC213x.h>
#include<math.h>

int main()
{
	int y=0;
	int save[128] = {0};
	int sign_vdive_plus = 0, sign_vdive_minus = 0;
	int value = 0; 		// the value of converted audio from input ADC channel to the output DAC channel
	int v_p_div = 16; 
	
	//           RS     RW     EN    CS1    CS2    D0      D1     D2     D3     D4     D5     D6     D7*/
	GLCD_SetUp(P1_16, P1_17, P1_18, P1_19, P1_20, P1_21, P1_22, P1_23, P1_24, P1_25, P1_26, P1_27, P1_28);

	GLCD_Init();

	PINSEL0 |= 0x0;
	IO0DIR = IO0DIR  & 0xffffff00;
	GLCD_DrawVertLine(0,0,64,1);
	GLCD_DrawVertLine(15,0,64,1);
	GLCD_DrawVertLine(31,0,64,1);
	GLCD_DrawVertLine(47,0,64,1);
	GLCD_DrawVertLine(63,0,64,1);
	GLCD_DrawVertLine(79,0,64,1);
	GLCD_DrawVertLine(95,0,64,1);
	GLCD_DrawVertLine(111,0,64,1);
	GLCD_DrawVertLine(127,0,64,1);

	GLCD_DrawHoriLine(0,0,128,1);
	GLCD_DrawHoriLine(0,15,128,1);
	GLCD_DrawHoriLine(0,31,128,1);
	GLCD_DrawHoriLine(0,47,128,1);
	GLCD_DrawHoriLine(0,63,128,1);

	PINSEL1 = PINSEL1 | 0x00080000; // adjust pin p0.25 as AOUT
	PINSEL1 |= 1<<22; // Adjust pin p0.27 as AD0.0
	AD0CR=0x00200301; // AD0.0: select AD.0, CLKDIV = 10, CLKS = 10 BIT, The A/D converter is operational

	while(1){
		AD0CR|=1<<24; // start conversion now
		while((AD0DR&1<<31)==0); // wait for conversion to complete
		value = (AD0DR&0x0000ffc0)>>6;// samples datas
		
		if ((IO0PIN&0x00000004) == 0x00000004){
			if ((((save[y]+1)%16 != 0) && ((y+1)%16 != 0)) && (save[y] != 0) && (y != 0)){
				GLCD_SetDot(y, save[y], 0);	
			}
			
			save[y] = 31 + ((511-value)/v_p_div);
			
			GLCD_SetDot(y, save[y], 1);
		}
		
		if (y == 127 )
			y = 0;
		else
			y++;
		
		if ((sign_vdive_plus == 0) && (IO0PIN&0x00000001) == 0x00000001){
			if (v_p_div < 32)
				v_p_div = v_p_div + 1;
			sign_vdive_plus = 1;
		}
		else if ((sign_vdive_plus == 1) && (IO0PIN&0x00000001) == 0x00000000){
			sign_vdive_plus = 0;
		}

		if ((sign_vdive_minus == 0) && (IO0PIN&0x00000002) == 0x00000002){
			if (v_p_div > 1)
				v_p_div = v_p_div - 1;
			sign_vdive_minus = 1;
		}
		else if ((sign_vdive_minus == 1) && (IO0PIN&0x00000002) == 0x00000000){
			sign_vdive_minus = 0;
		}		
	}
}

