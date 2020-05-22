#include "PLL.h"
#include "TM4C123.h"                    // Device header

void initPLL(uint8_t frequency){
	SYSCTL->RCC2 = 0x80000000; //RCC2 overrides configuration done on RCC
	SYSCTL->RCC2 |= 0x00000800; //BYPASS set.
	SYSCTL->RCC &= ~(0x00400000); //and USESYSDIV is cleared.
	SYSCTL->RCC |= 0x00000540; //Select crystal freq and oscillator source.
	SYSCTL->RCC2 &= ~(0x00002000); //PWRDWN is cleared.
	SYSCTL->RCC2 |= (1<<30);
	switch(frequency){
		case (Bus_3125MHz):
			SYSCTL->RCC2 |= 0x0F800000;
			SYSCTL->RCC2 |= 0x00400000; //set bit 22 to get 3.125Mhz

		break;
		case (Bus_80MHz):
			SYSCTL->RCC2 |= 0x41000000; //Set the SYSDIV2 to the desired value. (80MHz in this case)
			SYSCTL->RCC2 &= ~(0x00400000); //clear bit 22 to get 80Mhz
			SYSCTL->RCC |= 0x00400000; //set USESYSDIV.

		break;
		default:
			SYSCTL->RCC2 |= 0x41000000; //Set the SYSDIV2 to the desired value. (80MHz in this case)
			SYSCTL->RCC2 &= ~(0x00400000); //clear bit 22 to get 80Mhz
			SYSCTL->RCC |= 0x00400000; //set USESYSDIV.

		break;
		
	}
	SYSCTL->RCC |= 0x00400000; //set USESYSDIV.
	while((SYSCTL->RIS&0x40) == 0){}; //wait for PLL to be ready.
		
	//SYSCTL->RCC &= ~(0x00000800);//BYPASS is cleared and PLL is operating.
	SYSCTL->RCC2 &= ~(0x00000800);//BYPASS is cleared and PLL is operating.
}
