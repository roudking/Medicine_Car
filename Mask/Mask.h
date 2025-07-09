
#ifndef _MASK_H
#define _MASK_H

#include "tim_it.h"
#include "serial.h"
#include "my_delay.h"
#include "Driver.h"
#include "Servo.h"
#include "my_HWT101.h"
#include "Raspberry_uart.h"

typedef struct 
{
    MOTOR motor1;
    MOTOR motor2;
    SERVO servo;
    IMU imu;
}CAR;

void Mask_start(void);

#endif
