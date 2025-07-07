#ifndef _MY_GPIO_H
#define _MY_GPIO_H

#include <ti/driverlib/dl_gpio.h>

int gpio_readpin(GPIO_Regs * gpio,uint32_t pins);
void gpio_setpin(GPIO_Regs * gpio,uint32_t pins);
void gpio_resetpin(GPIO_Regs * gpio,uint32_t pins);

#endif