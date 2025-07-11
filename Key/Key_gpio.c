#include "Key_gpio.h"

int Key_getvalue(KEY_CONFIG config)
{
  return gpio_readpin(config.gpio_port, config.gpio_pin);
}