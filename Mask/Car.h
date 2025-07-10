#ifndef _CAR_H
#define _CAR_H

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

    PID trance_pid;
}CAR;

void Car_settrancepid(CAR *car, PID trancepid);

float Car_trancepidcal(CAR *car);


#endif