#include "PWM.h"
#include "TM4C123.h"                    // Device header

/****This is a program to initialize the hardware PWM0 block of the
---TM4C123GH6PM microcontroller.
---Input: Period, Duty Cycle
---Output: Properly configured PWM signal.
****/
void initPWM(uint16_t period, uint16_t duty){
	SYSCTL->RCGCPWM |= 0x01;
	while(!(SYSCTL->PRPWM&0x01)){};
	SYSCTL->RCGCGPIO |= 0x02;
	while(!(SYSCTL->PRGPIO&0x02)){};
	GPIOB->AFSEL |= 0x40;
	GPIOB->AMSEL &= ~(0x40);
	GPIOB->PCTL &= ~0x0F000000;	
	GPIOB->PCTL |= 0x04000000;
	GPIOB->DEN |= 0x40;
	SYSCTL->RCC |= (1<<20);
	SYSCTL->RCC &= ~(0x000F0000);	
	SYSCTL->RCC |= 0x000A0000;
	PWM0->CTL = 0x00000000;
	PWM0->_0_GENA = 0xC8;
	//PWM0->_0_GENB = 0x0000080C;		
	PWM0->_0_LOAD = period-1;
	PWM0->_0_CMPA = duty-1;
	//PWM0->_0_CMPB = 1 - duty;
	PWM0->_0_CTL |= 0x01;
	PWM0->ENABLE |= 0x01;
}

void PWMDuty(uint16_t duty){
	PWM0->_0_CMPA = duty-1;
	
}

