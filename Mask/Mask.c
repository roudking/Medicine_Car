#include "Mask.h"

//定义对象
CAR car;
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

void Mask_start(void)
{
    //电机初始化
	 Driver_creatmotor(&(car.motor1),pidL,leftdriver);
	 Driver_creatmotor(&(car.motor2),pidR,rightdriver);
     Driver_init(&(car.motor1));
     Driver_init(&(car.motor2));

    //舵机初始化

    //树莓派串口初始化
     Raspberry_uartinit();

    //陀螺仪初始化
     Myhwt101_init(); 
  
    //开启任务定时中断
     tim_it_start(Mask_Timer_INST,Mask_Timer_INST_INT_IRQN);
	
}

void Mask_Timer_INST_IRQHandler(void)
{ 
	Driver_getmotor_currentspeed(&(car.motor1));
	Driver_getmotor_currentspeed(&(car.motor2));

    Myhwt101_getdata(&(car.imu));

    //输出速度信息    
    // Debugger_printf("%d,%d\n",car.motor1.currentspeed,car.motor2.currentspeed);
    //输出角度信息
    Debugger_printf("%.3f,%.3f\n",car.imu.current_yaw,car.imu.real_yaw);

    Driver_setspeed(&(car.motor1),&(car.motor2));

}



//TEST代码
// 	int time = 1500;
// 	static int i = 0;
//   if(i<time/10)
// 	{
//     Driver_setmotor_targetspeed(&(car.motor2),0.0);
//     Driver_setmotor_targetspeed(&(car.motor1),0.0);
// 		i++;
// 	}
// 	else if(i < 2*time/10)
// 	{
//     Driver_setmotor_targetspeed(&(car.motor2),25.0);
//     Driver_setmotor_targetspeed(&(car.motor1),25.0);
// 		i++;	
// 	}
// 	else if(i < 3*time/10)
// 	{
//     Driver_setmotor_targetspeed(&(car.motor1),40.0);
//     Driver_setmotor_targetspeed(&(car.motor2),40.0);
// 		i++;	
// 	}    
// 	else if(i < 4*time/10)
// 	{
//     Driver_setmotor_targetspeed(&(car.motor1),25.0);
//     Driver_setmotor_targetspeed(&(car.motor2),25.0);
// 		i++;
// 	}
//     else if(i < 5*time/10){
//     Driver_setmotor_targetspeed(&(car.motor1),0.0);  
//     Driver_setmotor_targetspeed(&(car.motor2),0.0);
//     i++;
//     }
//   else if(i < 6*time/10){
//     Driver_setmotor_targetspeed(&(car.motor1),-25.0);  
//     Driver_setmotor_targetspeed(&(car.motor2),-25.0);
//     i++;
//     }
//   else if(i < 7*time/10){
//     Driver_setmotor_targetspeed(&(car.motor1),-40.0);  
//     Driver_setmotor_targetspeed(&(car.motor2),-40.0);
//     i++;
//     }
//   else if(i < 8*time/10){
//     Driver_setmotor_targetspeed(&(car.motor1),-25.0);  
//     Driver_setmotor_targetspeed(&(car.motor2),-25.0);
//     i++;
//     }
//   else{
//     Driver_setmotor_targetspeed(&(car.motor1),0.0);  
//     Driver_setmotor_targetspeed(&(car.motor2),0.0);
//   }