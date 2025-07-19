#ifndef _PID_H
#define _PID_H

#include "math.h"

typedef double PID_TYPE;
// typedef float PID_TYPE;

typedef struct
{

	PID_TYPE kff; //前馈系数
	PID_TYPE kp; //比例系数
	PID_TYPE ki; //积分系数
	PID_TYPE kd; //微分系数

	PID_TYPE out_xianfu; //输出限幅
	PID_TYPE integrate_xianfu; //积分限幅

    PID_TYPE last_targetvalue; //上次目标值	
	PID_TYPE last_bias;  //上次偏差
	PID_TYPE last2_bias; //上上次偏差
	PID_TYPE integral;   //积分值
	PID_TYPE outvalue;   //输出值
	PID_TYPE last_outvalue; //上次输出值

}PID;


//PID相关数学函数
  //限幅函数
PID_TYPE xianfu(PID_TYPE value, PID_TYPE min, PID_TYPE max);

//暴露微分
PID_TYPE position_divAPI_PID_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID_TYPE current_div, PID* pid);
// 位置式 PID 计算函数（带输出限幅和积分抗饱和）
PID_TYPE positionPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid);
//位置式 FFPID 计算函数
PID_TYPE positionFFPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid);
//增量式 PID 计算函数
PID_TYPE deltaPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid);
//增量式 FFPID 计算函数
PID_TYPE deltaFFPid_Cal(PID_TYPE targetvalue, PID_TYPE currentvalue, PID* pid);
//清除PID内存
void pidmemory_clear(PID* pid);

#endif
