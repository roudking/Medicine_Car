#ifndef _CAR_H
#define _CAR_H

#include "Driver.h"
#include "Servo.h"
#include "my_HWT101.h"
#include "Raspberry_Pi.h"
#include "Laser.h"
#include "Key.h"
#include "K230.h"
#include "K210.h"

typedef struct
{
    int turnstatus;
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
    K210  k210;
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


//任务流程
//stop
int Car_stopfuc(CAR *car);

//wait_keyon
int Car_waitkeyonfuc(CAR *car);

//wait_keyoff
int Car_waitkeyofffuc(CAR *car);

//turnright
int Car_turnrightfuc(CAR *car);

//turnleft
int Car_turnleftfuc(CAR *car);

//turnback
int Car_turnbackfuc(CAR *car);

//goto_T
int Car_gotoTfuc(CAR *car); 

//get_num
int Car_getnumfuc(CAR *car);



#endif
