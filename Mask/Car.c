#include "Car.h"


//已整定pid
PID pidL = {
    .kp = 170.5,
    .ki =43.0,
    .kd = 0.0,
    .out_xianfu = 7199.0
};
PID pidR = {
    .kp = 180.5,
    .ki =43.0,
    .kd = 0.0,
    .out_xianfu = 7199.0
};

PID pidtrance = {
    .kp = 0.75,
    .ki = 0.00,
    .kd = 2.77,
    .out_xianfu = 6.5
};

PID pidturn = {
    .kp = 0.75,
    .ki = 0.00,
    .kd = 3.37,
    .out_xianfu = 35.0
};

PID pidposition = {
    .kp = 9.5,
    .ki = 0.00,
    .kd = 11.0,
    .out_xianfu = 20.0
};

//载入任务
static int Mask_getmasknum(MASK mask)
{
    return sizeof(mask.mask_list)/sizeof(mask.mask_list[0]);
}

void Car_setmask(CAR *car,MASK mask)
{
    car->mask = mask;
    car->mask.mask_num = Mask_getmasknum(mask);
	car->mask.mask_pc = 0; // 初始化mask_pc为0
}

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
        if(car->basespeed == 0.0)
        {
            return Car_trancepidcal(car);
        }
        else
        {
            return Car_trancepidcal(car) + Car_positionpidcal(car);
        }
     }

}

//设置基础速度
void Car_setbasespeed(CAR *car, float basespeed)
{
    car->basespeed = basespeed;
}

//获取当前距离
void Car_getdistance(CAR *car)
{
   car->distance += (car->motor1.currentspeed + car->motor2.currentspeed) / 2.0;
}   



// typedef enum
// {
//     stop, //停止
//     wait_keyon, //等待按键放置药品  
//     wait_keyoff, //等待按键取走药品
//     turnright, //右转
//     turnleft, //左转
//     turnback, //掉头
//     go_over, //过弯
//     goto_T, //到达T路口
//     goto_N, //到达N路口
//     get_num, //获取数字
//     get_mode, //获取模式
//     get_run, //获取运行状态
//     echo_park, //回复到位
//     mask_load //加载任务流程
//     wait_start //等待开始
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
   static int pc = 0;
   if(pc == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw - 90.0; //设置转弯角度
       pc++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc = 0; //重置计数器
       return 1; //转弯完成
     }

   }
}

//turnleft
int Car_turnleftfuc(CAR *car)
{
   static int pc = 0;
   if(pc == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw + 90.0; //设置转弯角度
       pc++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc = 0; //重置计数器
       return 1; //转弯完成
      }

    }
}

//turnback
int Car_turnbackfuc(CAR *car)
{
   static int pc = 0;
   if(pc == 0)
   {
       car->status.turnstatus = 1;
       car->imu.zero_yaw = car->imu.zero_yaw + 180.0; //设置转弯角度
       pc++;
       return 0; //转弯开始
   }
   else {
     if(car->status.turnstatus == 1) {
       return 0; //保持当前状态
    }
      else {
       pc = 0; //重置计数器
       return 1; //转弯完成
     }

   }
}

//get_num
int Car_getnumfuc(CAR *car)
{
    static int pc = 0;
    if(pc == 0)
    {
        K210_numstatusIN(1); //启动K210获取数字 标志位置位
        K210_printf("{\"cmd\":\"num\"}\n");
        pc++;
        return 0; //开始获取
    }
    else {
        K210_getnumstatus(&(car->k210));
        if(car->k210.status.numstatus == 1) {
            return 0; //保持当前状态
        }
        else {
           K210_getnumdata(&(car->k210)); //获取数字
            pc = 0; //重置计数器
            return 1; //获取完成
        }
    }
}


//go_over
const float go_over_distance = 550.0; //过弯距离
int Car_gooverfuc(CAR *car)
{
    static int pc = 0;
    if(pc == 0)
    {
     car->distance = 0; //重置距离
        pc++;
        return 0; //开始转弯
    }
    else {
        if(car->distance < go_over_distance) 
        {
            return 0; //保持当前状态
        }
        else {
            car->distance = 0; //重置距离
            pc = 0; //重置计数器
            return 1; //过弯完成
        }
    }
}

//goto_T
const float basespeed = 45.0; //基础速度
int Car_gotoTfuc(CAR *car)
{
    Car_setbasespeed(car, basespeed);
    K230_gettstatus(&(car->k230));
    if(car->k230.status.tstatus == 1) {
        //到达T路口，执行相应操作
        return 1; //到达T路口
    }
    else {
        //未到达T路口，继续前进
        return 0; //保持当前状态
    }

}

//goto_N
int Car_gotoNfuc(CAR *car)
{
    Car_setbasespeed(car, basespeed);
    K230_getnstatus(&(car->k230));
    if(car->k230.status.nstatus == 1) {
        //到达N路口，执行相应操作
        return 1; //到达N路口
    }
    else {
        //未到达N路口，继续前进
        return 0; //保持当前状态
    }
}

//get_mode
int Car_getmodefuc(CAR *car)
{
    Raspberry_getmodedata_update(&(car->raspberry));
    if(car->raspberry.status.modedata_update == 1) {
         //模式数据已更新
         Raspberry_getmodedata(&(car->raspberry)); //获取模式数据
         //发送{"cmd":"mode","result":"ok"}
         Raspberry_printf("{\"cmd\":\"mode\",\"result\":\"ok\"}\n");
         return 1; //获取完成
    }
    else {
         return 0; //保持当前状态
    }
}

//wait_run
int Car_waitrunfuc(CAR *car)
{
    Raspberry_getrun(&(car->raspberry));
    if(car->raspberry.status.run == 1) {
         return 1; //获取完成
    }
    else {
         return 0; //保持当前状态
    }
}

//echo_park
int Car_echoparkfuc(CAR *car)
{
//回复{"cmd":"run","parked":1} //到位
    Raspberry_printf("{\"cmd\":\"run\",\"parked\":1}\n");
    return 1; //回复完成
}

//wait_start
int Car_waitstartfuc(CAR *car)
{
    Raspberry_getstart(&(car->raspberry));
    if(car->raspberry.status.start == 1) {
        //开始状态为1，开始执行任务
        return 1; //开始执行任务
    }
    else {
        //开始状态为0，保持等待
        return 0; //保持当前状态
    }
}

//
MASK mask_a = {
    .mask_list = {    
       stop,  
       goto_T,
       go_over,
       goto_T,
       go_over,
       turnleft,
       goto_N,
       go_over,
       stop,
       echo_park,      
       wait_start,

       turnback,
       goto_N,
       go_over,
       stop
    
    },
    .mask_num = 14
};

MASK mask_b = {
    .mask_list = {    
       stop,  
       goto_T,
       go_over,
       goto_T,
       go_over,
       turnright,
       goto_N,
       go_over,
       stop,
       echo_park,      
       wait_start,

       turnback,
       goto_N,
       go_over,
       stop
    },
    .mask_num = 14
};

MASK mask_c = {
    .mask_list = {    
     stop,
     goto_T,
     go_over,
     goto_T,
     go_over,
     turnright,
     goto_N,
     go_over,
     stop,
     echo_park,
     wait_start,

     turnback,
     goto_T,
     go_over,
     turnright,
     goto_T,
     get_num,
     go_over,
     mask_load
    },
    .mask_num = 18
};

MASK mask_c1 = {
    .mask_list = {    
    turnright,
    goto_T,
    get_num,
    go_over,
    mask_load
    },
    .mask_num = 5
};

MASK mask_c2 = {
    .mask_list = {    
    turnleft,
    goto_T,
    get_num,
    go_over,
    mask_load
    },
    .mask_num = 5
};

MASK mask_c3 = {
    .mask_list = {
        turnright,
        goto_N,
        go_over,
        stop
    },
    .mask_num = 4
};

MASK mask_c4 = {
    .mask_list = {
        turnleft,
        goto_N,
        go_over,
        stop
    },
    .mask_num = 4
};

//mask_load
int Car_maskloadfuc(CAR *car)
{
  if(car->raspberry.mode.target == 0)
  {
    if(car->raspberry.mode.park == 'A')
    {
        Car_setmask(car, mask_a);
    }
    else if(car->raspberry.mode.park == 'B')
    {
        Car_setmask(car, mask_b);
    }
  }
  else if(car->raspberry.mode.target == 1)
  {
    static int pc = 0;
    if(pc == 0)
    {
        car->target_num = car->k210.num[0]; //设置目标数字
        Car_setmask(car, mask_c);
        pc++;
    }
    else if(pc == 1)
    {
      if(car->k210.num[0] == car->target_num || car->k210.num[1] == car->target_num)
      {
        Car_setmask(car, mask_c1);
      }
      else{
        Car_setmask(car, mask_c2);
      }
        pc++;
    }
    else if(pc == 2)
    {
      if(car->k210.num[0] == car->target_num || car->k210.num[1] == car->target_num)
      {
        Car_setmask(car, mask_c3);
      }
      else{
        Car_setmask(car, mask_c4);
      }
   }
 }
  
   return 1; //加载完成
}
