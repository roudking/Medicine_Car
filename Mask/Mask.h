
#ifndef _MASK_H
#define _MASK_H

#include "tim_it.h"
#include "Driver.h"
#include "Servo.h"
#include "serial.h"
#include "my_delay.h"
#include "Raspberry_uart.h"

typedef struct 
{
    MOTOR motor1;
    MOTOR motor2;
    SERVO servo;
}CAR;

void Mask_start(void);

#endif
