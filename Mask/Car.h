#ifndef _CAR_H
#define _CAR_H

#include "Driver.h"
#include "Servo.h"
#include "my_HWT101.h"
#include "Raspberry_Pi.h"
#include "Laser.h"
#include "Key.h"
#include "K230.h"

typedef struct
{
    int turn_state;
}CAR_STATUS;

typedef enum
{
   wait_keyon,
   wait_keyoff,
   get_num,
   goto_T,
   go_over,
   turnright,
   turnleft,
   turnback,
   stop
}MASK_ENUM;

typedef struct
{
    MASK_ENUM mask_list[200];
    int mask_num;
}MASK;


typedef struct 
{
    MOTOR motor1;
    MOTOR motor2;
    SERVO servo;
    RASPBERRY raspberry;
    K230  k230;
    LASER rled;
    LASER gled;
    LASER yled;
    IMU imu;
    MYKEY key;

    PID trance_pid;
    PID turn_pid;
    PID position_pid;

    float basespeed;

    MASK mask;

    CAR_STATUS status;
}CAR;

//设置巡线角度环PID
void Car_settrancepid(CAR *car, PID trancepid);
float Car_trancepidcal(CAR *car);

//设置转向环PID 
void Car_setturnpid(CAR *car, PID turnpid);
float Car_turnpidcal(CAR *car);

//设置位置环PID
void Car_setpositionpid(CAR *car, PID positionpid);
float Car_positionpidcal(CAR *car);

//获得左右轮差速
float Car_getdeltaspeed(CAR *car);

//设置基础速度
void Car_setbasespeed(CAR *car, float basespeed);


#endif
