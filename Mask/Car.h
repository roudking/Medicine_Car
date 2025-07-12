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
    int turn_state;

}CAR_STATE;

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
    PID turn_pid;

    CAR_STATE state;
}CAR;

//设置巡线角度环PID
void Car_settrancepid(CAR *car, PID trancepid);
float Car_trancepidcal(CAR *car);

//设置转向环PID 
void Car_setturnpid(CAR *car, PID turnpid);
float Car_turnpidcal(CAR *car);

//获得左右轮差速
float Car_getdeltaspeed(CAR *car);

//获取目标速度
void Car_gettargetspeed(CAR *car);

//获取目标角度
void Car_gettargetangle(CAR *car);
void Car_settargetangle(CAR *car);

//获取目标指示灯颜色
void Car_getcolor(CAR *car);
void Car_setcolor(CAR *car);

//获取目标按键状态
void Car_getkeystatus(CAR *car);
void Car_echokeystatus(CAR *car);

//获取陀螺仪复位状态
void Car_getresetstatus(CAR *car);
void  Car_resetimu(CAR *car);

#endif