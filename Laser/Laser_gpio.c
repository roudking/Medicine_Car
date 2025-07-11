#include "Laser_gpio.h"

void _Laser_on(LASER_CONFIG config)
{
    gpio_setpin(config.gpio_port, config.gpio_pin);
}

void _Laser_off(LASER_CONFIG config)
{
    gpio_resetpin(config.gpio_port, config.gpio_pin);
}
