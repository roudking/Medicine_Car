#ifndef _BEEP_CONFIG_H
#define _BEEP_CONFIG_H

#include "my_gpio.h"
#include "ti_msp_dl_config.h"

typedef struct {
    GPIO_Regs *gpio_port;
    uint32_t gpio_pin;
}BEEP_CONFIG;

extern BEEP_CONFIG beep_config;

#endif
