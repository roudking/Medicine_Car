#include "Mask.h"

//定义对象
CAR car;
//已整定pid
PID pidL = {
    .kp = 150.0,
    .ki =35.0,
    .kd = 0.0
};
PID pidR = {
    .kp = 200.0,
    .ki = 11.5,
    .kd = 0.0
};

void Mask_start(void)
{
// //电机初始化
	 Driver_creatmotor(&(car.motor1),pidL,leftdriver);
	 Driver_creatmotor(&(car.motor2),pidR,rightdriver);
     Driver_init(&(car.motor1));
     Driver_init(&(car.motor2));

// //舵机初始化

// //树莓派串口初始化

  
// //开启任务定时中断
   tim_it_start(Mask_Timer_INST,Mask_Timer_INST_INT_IRQN);
	
}

void Mask_Timer_INST_IRQHandler(void)
{ 
	Driver_getmotor_currentspeed(&(car.motor1));
	Driver_getmotor_currentspeed(&(car.motor2));

//TEST代码
	int time = 3000;
	static int i = 0;
  if(i<time/10)
	{
   Driver_setmotor_targetspeed(&(car.motor1),0.0);
		i++;
	}
	else if(i < 2*time/10)
	{
  Driver_setmotor_targetspeed(&(car.motor1),25.0);
		i++;	
	}
	else if(i < 3*time/10)
	{
  Driver_setmotor_targetspeed(&(car.motor1),40.0);
		i++;	
	}    
	else if(i < 4*time/10)
	{
  Driver_setmotor_targetspeed(&(car.motor1),25.0);
		i++;
	}
    else {
      Driver_setmotor_targetspeed(&(car.motor1),0.0);
    }


    Debugger_printf("%d\n",car.motor1.currentspeed);
    Driver_setspeed(&(car.motor1),&(car.motor2));

}



//TEST代码
//	int time = 1000;
//	static int i = 0;
//  if(i<time/10)
//	{
//    Servo_settargetangle(&(car.servo),60.0);
//	  Servo_gotoangle(&(car.servo));
//		i++;
//	}
//	else if(i < 2*time/10)
//	{
//   Servo_settargetangle(&(car.servo),120.0);
//	  Servo_gotoangle(&(car.servo));
//		i++;
//		i++;	
//	}