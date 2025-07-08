#ifndef _LASER_CONFIG_H
#define _LASER_CONFIG_H

#include "my_gpio.h"

typedef struct
{
    GPIO_Regs *gpio_port;  // GPIO port for the laser
    uint32_t  gpio_pin;       // GPIO pin for the laser
} LASER_CONFIG;

extern LASER_CONFIG laser_config;

#endif

