#ifndef KEY_CONFIG_H
#define KEY_CONFIG_H

#include "my_gpio.h"
#include "ti_msp_dl_config.h"

typedef struct
{
    GPIO_Regs *gpio_port;  // GPIO port for the laser
    uint32_t  gpio_pin;       // GPIO pin for the laser
} KEY_CONFIG;

extern KEY_CONFIG key1_config;
// extern KEY_CONFIG key2_config;

#endif // KEY_CONFIG_H