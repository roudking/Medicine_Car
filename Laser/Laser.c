#include "Laser.h"

void Laser_create(LASER *laser, LASER_CONFIG laser_config)
{
     laser->config = laser_config;
}

void Laser_on(LASER *laser)
{
   _Laser_on(laser->config);
}

void Laser_off(LASER *laser)
{
  _Laser_off(laser->config);
}
