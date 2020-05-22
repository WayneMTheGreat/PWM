#ifndef PLL_H_
#define PLL_H_
#include <stdint.h>

#define Bus_80MHz			0x02 //80MHz Bus Clock
#define Bus_3125MHz   0x3F //3.125MHz Bus Clock



/*
---Configures the Phase Locked Loop of the MCU.
---Input: The desired bus frequency for the PLL. (Only two values for now for testing are defined as macros)
---Output: None. (The bus clock should be operating at the desired frequency)
*/
void initPLL(uint8_t frequency);
#endif
