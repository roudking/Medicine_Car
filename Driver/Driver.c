#include "Driver.h"

//PID pidL = {25.0,5.0,0.0};
//PID pidR = {25.0,5.0,0.0};

//实例化电机
void Driver_creatmotor(MOTOR *mymotor, PID pid, DRIVER_CONFIG driver)
{
	  mymotor->pid = pid;
	  pidmemory_clear(&(mymotor->pid));
	
	  mymotor->lastspeed = 0;
	  mymotor->targetspeed = 0;
	
	  mymotor->config = driver;
}

//初始化电机驱动边上外设
void Driver_init(MOTOR *motor)
{
     DriverEncoder_start(motor->config);
     DriverPwm_start(motor->config);
}


void Driver_setmotorpwm(MOTOR *motor1,int pwm1, MOTOR *motor2,int pwm2)
{
    Driver_setpwm(motor1->config,pwm1);
   	Driver_setpwm(motor2->config,pwm2);
}


void Driver_setmotor_targetspeed(MOTOR *motor,int target_speed)
{
     motor -> targetspeed = target_speed;
}

void Driver_getmotor_currentspeed(MOTOR *motor)
{
	motor->currentspeed = DriverEncoder_getcounter(motor->config);
}


void Driver_setspeed(MOTOR *motor1,MOTOR *motor2)
{
	int pwm1 = (int) deltaPid_Cal((float) (motor1->targetspeed), (float) (motor1->currentspeed), &(motor1->pid));
	int pwm2 = (int) deltaPid_Cal((float) (motor2->targetspeed), (float) (motor2->currentspeed), &(motor2->pid));

    if (motor1->targetspeed == 0) {
	    pwm1 = 0;
	    pidmemory_clear(&(motor1->pid));
    }
    if (motor2->targetspeed == 0) {
	    pwm2 = 0;
	    pidmemory_clear(&(motor2->pid));
    }
   
   Driver_setmotorpwm(motor1,pwm1,motor2,pwm2);
}

void Driver_setspeedwithfliter(MOTOR *motor1, MOTOR *motor2, float filter) {
	motor1->flitspeed = (float) motor1->flitspeed * filter + (float) motor1->currentspeed * (1.0 - filter);
	motor2->flitspeed = (float) motor2->flitspeed * filter + (float) motor2->currentspeed * (1.0 - filter);

	int pwm1 = (int) deltaPid_Cal((float) (motor1->targetspeed), (float) (motor1->flitspeed), &(motor1->pid));
	int pwm2 = (int) deltaPid_Cal((float) (motor2->targetspeed), (float) (motor2->flitspeed), &(motor2->pid));

	if (motor1->targetspeed == 0 && motor2->targetspeed == 0) {
		pwm1 = 0;
		pwm2 = 0;
		pidmemory_clear(&(motor1->pid));
		pidmemory_clear(&(motor2->pid));
	}

	Driver_setmotorpwm(motor1, pwm1, motor2, pwm2);
}
