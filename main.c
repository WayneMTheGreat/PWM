#include "TM4C123.h"                    // Device header
#include "PLL.h"
#include "PWM.h"

void timerInit(void);
void delaySec80MHz(int delay);
void delaySec3125MHz(int delay);

int main(){
	initPLL(Bus_3125MHz);
	timerInit();
	initPWM(2000,150);
	GPIOB->DIR |= 0x08;
	GPIOB->DEN |= 0x08;
	GPIOB->PUR |= 0x08;
	GPIOB->DATA |= 0x08;
		
		while(1){
		
delaySec3125MHz(1);
GPIOB->DATA |= 0x08;
delaySec3125MHz(1);	
GPIOB->DATA = 0;

			
			
		}
	
}

void timerInit(void){
	SysTick->CTRL = 0;
	SysTick->LOAD = 16000000;
	SysTick->CTRL = 5;
	
}

void delaySec80MHz(int delay){
	for(int i = 0; i<(5*delay); i++){//so do it 5 times and that should be 1 sec.
	while((SysTick->CTRL&0x10000)==0){}; //if really is 80MHz should time out in 0.2 seconds.
}
}
void delaySec3125MHz(int delay){
	SysTick->LOAD = 3125000;
	for(int i = 0; i<delay; i++){//3,125,000 actions per second.
	while((SysTick->CTRL&0x10000)==0){}; //should time out every second if working properly.
	}
}
