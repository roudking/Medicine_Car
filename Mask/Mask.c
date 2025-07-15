#include "Mask.h"

//定义对象
CAR car;

MASK mask_start = {
    .mask_list = {        
       stop,
       get_num,
       get_mode,
       wait_run,
       wait_keyoff,
       mask_load
    },
    .mask_num = 12
};

void Mask_start(void)
{
    //电机初始化
	 Driver_creatmotor(&(car.motor1),pidL,leftdriver);
	 Driver_creatmotor(&(car.motor2),pidR,rightdriver);
     Driver_init(&(car.motor1));
     Driver_init(&(car.motor2));

    //LED初始化
     Laser_create(&(car.rled), rled_config);
     Laser_create(&(car.gled), gled_config);
     Laser_create(&(car.yled), yled_config);
    //上电关灯
     Laser_off(&(car.rled));
     Laser_off(&(car.gled));
     Laser_off(&(car.yled));

    //树莓派串口初始化
     Raspberry_init();

    //K230串口初始化
     K230_init();

    //陀螺仪初始化
     Myhwt101_init(); 
     Myhwt101_resetz(&(car.imu));

    //按键初始化
     Key_create(&(car.key), key1_config);

    //舵机初始化
     Servo_create(&(car.servo), servo_config);
     Servo_init(&(car.servo));
     Servo_setangle(&(car.servo), 103.0f);

    //设置trancePID
     Car_settrancepid(&car, pidtrance);

     //设置turnPID
     Car_setturnpid(&car, pidturn);

     //设置positionPID
     Car_setpositionpid(&car, pidposition);
     
     //设置任务流程
     Car_setmask(&car, mask_start);

    //开启任务定时中断
     tim_it_start(Mask_Timer_INST,Mask_Timer_INST_INT_IRQN);
	
}

void Mask_Timer_INST_IRQHandler(void)
{ 
	Driver_getmotor_currentspeed(&(car.motor1));
	Driver_getmotor_currentspeed(&(car.motor2));

    Car_getdistance(&car);

    Myhwt101_getdata(&(car.imu));

    K230_getposdata(&(car.k230));

    //获得左右轮差速
     float delta = Car_getdeltaspeed(&car);


     Mask_performmasks(&car);

     Driver_setmotor_targetspeed(&(car.motor1), car.basespeed - delta);
     Driver_setmotor_targetspeed(&(car.motor2), car.basespeed + delta);


    // Driver_setspeed(&(car.motor1),&(car.motor2));

}

//调试
    //输出速度信息    
    // Debugger_printf("%d,%d\n",car.motor1.currentspeed,car.motor2.currentspeed);
    //输出角度信息
    // Debugger_printf("%.3f,%.3f,%.3f\n",car.imu.current_yaw,car.imu.real_yaw,car.imu.zero_yaw);
    // Debugger_printf("%.3f,%.3f,%.3f,%.3f\n",car.imu.real_yaw,car.imu.zero_yaw,car.imu.current_yaw,delta);
    //输出位置信息
    // Debugger_printf("%.3f,%d,%d\n",car.k230.pos,car.k230.status.nstatus,car.status.tstatus);


//循迹角度环TEST
    // float delta = Car_trancepidcal(&car);
    // float base_speed = 25.0;
    // Driver_setmotor_targetspeed(&(car.motor1), base_speed - delta);
    // Driver_setmotor_targetspeed(&(car.motor2), base_speed + delta);

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

//稳定性测试任务流程
// MASK mask = {
//     .mask_list = {        
//         stop,
//         wait_keyoff,
//         goto_T,
//         go_over,
//         turnright,
//         goto_N,
//         go_over,
//         stop,
//         wait_keyon,
//         turnback,
//         goto_T,
//         go_over,
//         turnright,
//         goto_T,
//         go_over,
//         turnright,
//         goto_N,
//         go_over,
//         stop,
//         wait_keyoff,
//         turnback,
//         goto_T,
//         go_over,
//         turnright,
//         goto_T,
//         go_over,
//         turnright,
//         goto_T,
//         go_over,
//         turnright,
//         goto_N,
//         go_over,
//         stop,
//         wait_keyon,
//         turnback,
//         goto_T,
//         go_over,
//         turnleft,
//         goto_T,
//         go_over,
//         turnleft,
//         goto_N,
//         go_over,
//         stop
//     },
//     .mask_num = 40
// };