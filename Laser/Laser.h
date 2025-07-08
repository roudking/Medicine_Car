#ifndef _LASER_H
#define _LASER_H

#include "Laser_gpio.h"

typedef struct
{
    LASER_CONFIG config;  // Configuration for the laser
}LASER;

void Laser_on(LASER *laser);
void Laser_off(LASER *laser);


#endif
