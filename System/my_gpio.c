#include "my_gpio.h"

int gpio_readpin(GPIO_Regs * gpio,uint32_t pins)
{
	if(DL_GPIO_readPins(gpio,pins))	 
	{
	  return 1;
	}
	else
	{
		return 0;
	} 
	
}

void gpio_setpin(GPIO_Regs * gpio,uint32_t pins)
{
    DL_GPIO_setPins(gpio,pins);
}

void gpio_resetpin(GPIO_Regs * gpio,uint32_t pins)
{
    DL_GPIO_clearPins(gpio,pins);
}

