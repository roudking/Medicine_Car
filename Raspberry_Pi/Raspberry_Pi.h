#ifndef _RASPBERRY_PI_H
#define _RASPBERRY_PI_H

#include "string.h"

typedef struct{
     int modedata_update;
     int run;   //运行指令
     int start; //开始指令
}RASPBERRY_STATUS;

typedef struct{
     char park;
     int target;
}MODE;

typedef struct
{
    MODE mode; // 模式
	volatile RASPBERRY_STATUS status;
}RASPBERRY;

//获得模式数据
void Raspberry_modedataIN(MODE mode);
void Raspberry_getmodedata(RASPBERRY *raspberry);
void Raspberry_modedata_updateIN(int status);
void Raspberry_getmodedata_update(RASPBERRY *raspberry);

//获取运行指令
void Raspberry_runIN(int run);
void Raspberry_getrun(RASPBERRY *raspberry);

//获取开始指令
void Raspberry_startIN(int start);
void Raspberry_getstart(RASPBERRY *raspberry);

#endif
