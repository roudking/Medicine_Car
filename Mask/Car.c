#include "Car.h"

void Car_settrancepid(CAR *car, PID trancepid)
{
    car->trance_pid = trancepid;
}

float Car_trancepidcal(CAR *car)
{
    return positionPid_Cal(car->imu.zero_yaw, car->imu.real_yaw, &(car->trance_pid));
}

void Car_setturnpid(CAR *car, PID turnpid)
{
    car->turn_pid = turnpid;
}

float Car_turnpidcal(CAR *car)
{
    return positionPid_Cal(car->imu.zero_yaw, car->imu.real_yaw, &(car->turn_pid));
}

float Car_getdeltaspeed(CAR *car)
{
     if(car->state.turn_state == 1){
      //判定转弯完成,进行状态转换
       if(fabs(car->imu.real_yaw - car->imu.zero_yaw) < 2.0){  
          car->state.turn_state = 0;
         //到位回复
         //Raspberry_printf("{\"cmd\":\"turn\",\"result\":\"ok\"}\n");
       }
      return  Car_turnpidcal(car);
     }

     else if(car->state.turn_state == 0){
       return Car_trancepidcal(car);
     }

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
     car->imu.zero_yaw -= car->raspberry.angle;
    if(car->raspberry.angle != 0) 
    {
        car->state.turn_state = 1;
    }
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

void Car_getkeystatus(CAR *car)
{
     Key_read(&(car->key));
     Raspberry_getkeystatus(&(car->raspberry));
}

void Car_echokeystatus(CAR *car)
{
     if(car->raspberry.status.key_status == 1)
     {
        if(car->key.pin_value == 0)
        {
            Raspberry_printf("{\"cmd\":\"is_drug_loaded\",\"result\":true}\n");
        }
        else {
            Raspberry_printf("{\"cmd\":\"is_drug_loaded\",\"result\":false}\n");
        }
     }

}

void Car_getresetstatus(CAR *car)
{
   Raspberry_getresetstatus(&(car->raspberry));
}

void  Car_resetimu(CAR *car)
{
    if(car->raspberry.status.reset_status == 1)
    {
      car->imu.zero_yaw = car->imu.real_yaw;
      Raspberry_printf("{\"cmd\":\"reset\",\"result\":\"ok\"}\n");
    }
}