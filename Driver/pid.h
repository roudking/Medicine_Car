#ifndef _PID_H
#define _PID_H

#include "math.h"

typedef struct
{
    double last_targetvalue; //上次目标值
	double kff; //前馈系数
	
	double kp;
	double ki;
	double kd;
	double last_bias;  //上次偏差
	double last2_bias; //上上次偏差
	double integral;
	double outvalue;
	double last_outvalue;
	double out_xianfu;
	double integrate_xianfu;
}PID;


//PID相关数学函数
  //限幅函数
double xianfu(double value, double min, double max);

//暴露微分
double position_divAPI_PID_Cal(double targetvalue,double currentvalue,double current_div,PID* pid);
// 位置式 PID 计算函数（带输出限幅和积分抗饱和）
double positionPid_Cal(double targetvalue, double currentvalue, PID* pid);
//位置式 FFPID 计算函数
double positionFFPid_Cal(double targetvalue, double currentvalue, PID* pid);
//增量式 PID 计算函数
double deltaPid_Cal(double targetvalue, double currentvalue, PID* pid);
//增量式 FFPID 计算函数
double deltaFFPid_Cal(double targetvalue, double currentvalue, PID* pid);
//清除PID内存
void pidmemory_clear(PID* pid);

#endif
