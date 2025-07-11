#include "Car.h"

//已整定pid
PID pidL = {
    .kp = 155.5,
    .ki =36.0,
    .kd = 0.0
};
PID pidR = {
    .kp = 156.5,
    .ki = 40.0,
    .kd = 0.0
};

PID pidtrance = {
    .kp = 0.83,
    .ki = 0.00,
    .kd = 1.00,
    .out_xianfu = 15.0
};

void Car_settrancepid(CAR *car, PID trancepid)
{
    car->trance_pid = trancepid;
}

float Car_trancepidcal(CAR *car)
{
    return positionPid_Cal(car->imu.zero_yaw, car->imu.real_yaw, &(car->trance_pid));
}

void Car_gettargetspeed(CAR *car)
{
    //得到左右轮速度
     Raspberry_getleftspeed(&(car->raspberry));
     Raspberry_getrightspeed(&(car->raspberry));
}

void Car_gettargetangle(CAR *car)
{
     Raspberry_getangle(&(car->raspberry));
}

void Car_settargetangle(CAR *car)
{
     car->imu.zero_yaw += car->raspberry.angle;
}

void Car_getcolor(CAR *car)
{
     Raspberry_getcolor(&(car->raspberry));
}

void Car_setcolor(CAR *car)
{
     if(car->raspberry.led_color == 'r')
     {
       Laser_on(&(car->rled));
       Laser_off(&(car->gled));
       Laser_off(&(car->yled));
     }
     else if(car->raspberry.led_color == 'g')
     {
       Laser_off(&(car->rled));
       Laser_on(&(car->gled));
       Laser_off(&(car->yled));
     }
     else if(car->raspberry.led_color == 'y')
     {
       Laser_off(&(car->rled));
       Laser_off(&(car->gled));
       Laser_on(&(car->yled));
     }
     else{
       Laser_off(&(car->rled));
       Laser_off(&(car->gled));
       Laser_off(&(car->yled));
     }
}

void Car_getkeyaskstatus(CAR *car)
{
    Raspberry_getaskstatus(&(car->raspberry));
}

void Car_echokeyask(CAR *car)
{
    if(car->raspberry.keyask_status == 1)
    {
        Key_read(&(car->key));
        if(car->key.pin_value == 1)
        {
           Raspberry_printf("{\"cmd\":\"is_drug_loaded\",\"result\":true}\n");
        }
        else {
           Raspberry_printf("{\"cmd\":\"is_drug_loaded\",\"result\":false}\n");
        }
   
    }
}