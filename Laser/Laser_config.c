#include "Laser_config.h"

LASER_CONFIG rled_config = {
    .gpio_port = RGY_LED_R_Pin_PORT,
    .gpio_pin = RGY_LED_R_Pin_PIN
};

LASER_CONFIG gled_config = {
    .gpio_port = RGY_LED_G_Pin_PORT,
    .gpio_pin = RGY_LED_G_Pin_PIN
};

LASER_CONFIG yled_config = {
    .gpio_port = RGY_LED_Y_Pin_PORT,
    .gpio_pin = RGY_LED_Y_Pin_PIN
};
