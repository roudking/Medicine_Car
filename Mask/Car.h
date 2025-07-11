#ifndef _CAR_H
#define _CAR_H

#include "Driver.h"
#include "Servo.h"
#include "my_HWT101.h"
#include "Raspberry_Pi.h"
#include "Laser.h"
#include "Key.h"


typedef struct 
{
    MOTOR motor1;
    MOTOR motor2;
    SERVO servo;
    RASPBERRY raspberry;
    LASER rled;
    LASER gled;
    LASER yled;
    IMU imu;
    MYKEY key;


    PID trance_pid;
}CAR;

void Car_settrancepid(CAR *car, PID trancepid);
float Car_trancepidcal(CAR *car);

//从树莓派中得到数据
void Car_gettargetspeed(CAR *car);
void Car_settargetspeed(CAR *car);
void Car_gettargetangle(CAR *car);
void Car_settargetangle(CAR *car);
void Car_getcolor(CAR *car);
void Car_setcolor(CAR *car);
void Car_getkeyaskstatus(CAR *car);
void Car_echokeyask(CAR *car);

#endif