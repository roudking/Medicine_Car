#include "Key.h"

void Key_create(MYKEY *key, KEY_CONFIG config)
{
  key->config = config;
}

void Key_read(MYKEY *key)
{
  key->pin_value = Key_getvalue(key->config);
}