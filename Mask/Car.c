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

void Car_setpositionpid(CAR *car, PID positionpid)
{
    car->position_pid = positionpid;
}

float Car_positionpidcal(CAR *car)
{
    return positionPid_Cal(0.0, car->k230.pos, &(car->position_pid));
}

float Car_getdeltaspeed(CAR *car)
{
     if(car->status.turnstatus == 1){
      //判定转弯完成,进行状态转换
       if(fabs(car->imu.real_yaw - car->imu.zero_yaw) < 2.0){  
          car->status.turnstatus = 0;
       }
      return  Car_turnpidcal(car);
     }

     else if(car->status.turnstatus == 0){
       return Car_trancepidcal(car) + Car_positionpidcal(car);
     }

}

//设置基础速度
void Car_setbasespeed(CAR *car, float basespeed)
{
    car->basespeed = basespeed;
}






// typedef enum
// {
//    wait_keyon,
//    wait_keyoff,
//    get_num,
//    goto_T,
//    go_over,
//    turnright,
//    turnleft,
//    turnback,
//    stop
// }MASK_ENUM;

//任务流程书写；
//stop
int Car_stopfuc(CAR *car)
{
    Car_setbasespeed(car,0.0);
    return 1;
}

//wait_keyon
int Car_waitkeyonfuc(CAR *car)
{
    Key_read(&(car->key));
    if(car->key.pin_value == 1)
    {
        return 1; //药品已放置
    }
    else 
    {
        return 0; //药品未放置
    }
}

//wait_keyoff
int Car_waitkeyofffuc(CAR *car)
{
    Key_read(&(car->key));
    if(car->key.pin_value == 0)
    {
        return 1; //药品已取走
    }
    else 
    {
        return 0; //药品未取走
    }
}


//turnright
int Car_turnrightfuc(CAR *car)
{
   static int pc_cnt = 0;
   if(pc_cnt == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw + 90.0; //设置转弯角度
       pc_cnt++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc_cnt = 0; //重置计数器
       return 1; //转弯完成
     }

   }
}

//turnleft
int Car_turnleftfuc(CAR *car)
{
   static int pc_cnt = 0;
   if(pc_cnt == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw - 90.0; //设置转弯角度
       pc_cnt++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc_cnt = 0; //重置计数器
       return 1; //转弯完成
      }

    }
}

//turnback
int Car_turnbackfuc(CAR *car)
{
   static int pc_cnt = 0;
   if(pc_cnt == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw + 180.0; //设置转弯角度
       pc_cnt++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc_cnt = 0; //重置计数器
       return 1; //转弯完成
     }

   }
}

//goto_T
const float basespeed = 25.0; //基础速度
int Car_gotoTfuc(CAR *car)
{
    Car_setbasespeed(car, basespeed);
    return 1;
}

//get_num
int Car_getnumfuc(CAR *car)
{
    static int pc_cnt = 0;
    if(pc_cnt == 0)
    {
        K210_setnumstatus(1); //启动K210获取数字 标志位置位
        pc_cnt++;
        return 0; //开始获取
    }
    else {
        K210_getnumstatus(&(car->k210));
        if(car->k210.status.numstatus == 1) {
            return 0; //保持当前状态
        }
        else {
           K210_getnumdata(&(car->k210)); //获取数字
            pc_cnt = 0; //重置计数器
            return 1; //获取完成
        }
    }
}




