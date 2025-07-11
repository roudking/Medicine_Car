#ifndef _KEY_H
#define _KEY_H

#include "Key_gpio.h"
 
typedef struct
{
   int pin_value;
   KEY_CONFIG config; // Key configuration structure
}MYKEY;

void Key_create(MYKEY *key, KEY_CONFIG config);
void Key_read(MYKEY *key);

#endif
