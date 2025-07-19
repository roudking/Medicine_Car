#include "pid.h"


double xianfu(double value, double min, double max) {
    if (value > max) return max;
    if (value < min) return min;
    return value;
}

PID_TYPE position_divAPI_PID_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID_TYPE current_div, PID* pid) {

	pid->last_outvalue = pid->outvalue;
	// 1. 计算当前偏差
	PID_TYPE bias = targetvalue - currentvalue;

	// 2. 计算比例项
	PID_TYPE P = pid->kp * bias;

	// 3. 更新积分项（累积当前偏差）
	pid->integral += bias;

	// 4. 计算积分项和微分项
	PID_TYPE I = pid->ki * pid->integral;
		  //积分限幅 
	if(pid->integrate_xianfu > 0)
	 {
	  I = xianfu(I, -pid->integrate_xianfu, pid->integrate_xianfu);
	 }

	PID_TYPE D = current_div * pid->kd;

	// 5. 计算总输出
	   pid->outvalue = P + I + D;

	// 6. 对输出进行限幅
	 if(pid->out_xianfu > 0)
	 {
	 	 pid->outvalue = xianfu(pid->outvalue, -pid->out_xianfu, pid->out_xianfu);
	 }

	return pid->outvalue;
}


// 位置式 PID 计算函数（带输出限幅和积分抗饱和）
PID_TYPE positionPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid) {

		pid->last_outvalue = pid->outvalue;
	  // 1. 计算当前偏差
    PID_TYPE bias = targetvalue - currentvalue;

    // 2. 计算比例项
    PID_TYPE P = pid->kp * bias;

    // 3. 更新积分项（累积当前偏差）
    pid->integral += bias;

    // 4. 计算积分项和微分项
    PID_TYPE I = pid->ki * pid->integral;
	  //积分限幅 
	 if(pid->integrate_xianfu > 0)
	 {
	  I = xianfu(I, -pid->integrate_xianfu, pid->integrate_xianfu);
	 }
    PID_TYPE D = pid->kd * (bias - pid->last_bias);

    // 5. 计算总输出
     pid->outvalue = P + I + D;

	  // 6. 对输出进行限幅
	  if(pid->out_xianfu > 0)
		{
			  pid->outvalue = xianfu(pid->outvalue, -pid->out_xianfu, pid->out_xianfu);
		}

    // 8. 更新状态
    pid->last_bias = bias;      // 保存当前偏差，用于下一次微分计算

    return pid->outvalue;
}

// 位置式 FF-PID 计算函数
PID_TYPE positionFFPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid) {

	PID_TYPE Uff = pid->kff * targetvalue;

		pid->last_outvalue = pid->outvalue;
	  // 1. 计算当前偏差
    PID_TYPE bias = targetvalue - currentvalue;

    // 2. 计算比例项
    PID_TYPE P = pid->kp * bias;

    // 3. 更新积分项（累积当前偏差）
    pid->integral += bias;

    // 4. 计算积分项和微分项
    PID_TYPE I = pid->ki * pid->integral;
	  //积分限幅 
	 if(pid->integrate_xianfu > 0)
	 {
	  I = xianfu(I, -pid->integrate_xianfu, pid->integrate_xianfu);
	 }
    PID_TYPE D = pid->kd * (bias - pid->last_bias);

    // 5. 计算总输出
     pid->outvalue = P + I + D + Uff;

	  // 6. 对输出进行限幅
	  if(pid->out_xianfu > 0)
		{
			  pid->outvalue = xianfu(pid->outvalue, -pid->out_xianfu, pid->out_xianfu);
		}

    // 8. 更新状态
    pid->last_bias = bias;      // 保存当前偏差，用于下一次微分计算

    return pid->outvalue;
}

// 增量式 PID 计算函数
PID_TYPE deltaPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid)
{
	
		pid->last_outvalue = pid->outvalue;

	PID_TYPE bias, current_bias, outputvalue;
	
	current_bias = targetvalue - currentvalue;

  bias = current_bias - pid->last_bias;

	pid -> outvalue += pid->kp * bias + pid->ki * current_bias + pid->kd * (current_bias - 2*pid->last_bias + pid->last2_bias);

	pid->last2_bias = pid->last_bias; // 保存上上次偏差
	pid->last_bias = current_bias;
	
	if(pid->out_xianfu > 0)
	{
	  pid -> outvalue = xianfu(pid -> outvalue,-pid->out_xianfu,pid->out_xianfu);
	}

	return pid -> outvalue;
}

PID_TYPE deltaFFPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid)
{

	PID_TYPE delta_u = targetvalue - pid->last_targetvalue;

	pid->last_outvalue = pid->outvalue;

	PID_TYPE bias, current_bias, outputvalue;

	current_bias = targetvalue - currentvalue;

    bias = current_bias - pid->last_bias;
	
	pid -> outvalue += pid->kp * bias + pid->ki * current_bias + pid->kff * delta_u;

	pid->last_bias = current_bias;

	pid -> last_targetvalue = targetvalue;

	if(pid->out_xianfu > 0)
	{
	  pid -> outvalue = xianfu(pid -> outvalue,-pid->out_xianfu,pid->out_xianfu);
	}

	return pid -> outvalue;

}

void pidmemory_clear(PID* pid)
{
	  pid->integral  = 0.0;
      pid->last_bias = 0.0;
	  pid->last2_bias = 0.0;
	  pid->outvalue  = 0.0;
	  pid->last_outvalue = 0.0;
	  pid->last_targetvalue = 0.0;
}


