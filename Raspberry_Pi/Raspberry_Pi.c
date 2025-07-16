#include "Raspberry_Pi.h"

//树莓派缓存区
static RASPBERRY raspberry_temp;

void Raspberry_modedataIN(MODE mode)
{
    raspberry_temp.mode = mode; //设置模式
}

void Raspberry_getmodedata(RASPBERRY *raspberry)
{
    raspberry->mode = raspberry_temp.mode; //获取模式
}

void Raspberry_modedata_updateIN(int status)
{
    raspberry_temp.status.modedata_update = status; //更新模式数据状态
}

void Raspberry_getmodedata_update(RASPBERRY *raspberry)
{
    raspberry->status.modedata_update = raspberry_temp.status.modedata_update; //获取模式数据更新状态)
    //置位才清零标志位
    if(raspberry_temp.status.modedata_update == 1)
    {
        raspberry_temp.status.modedata_update = 0; //清零标志位
    }
}


void Raspberry_runIN(int run)
{
    raspberry_temp.status.run = run; //更新运行状态
}

void Raspberry_getrun(RASPBERRY *raspberry)
{
    raspberry->status.run = raspberry_temp.status.run; //获取运行状态
    //置位才清零标志位
    if(raspberry_temp.status.run == 1)
    {
        raspberry_temp.status.run = 0; //清零标志位
    }
}


void Raspberry_startIN(int start)
{
    raspberry_temp.status.start = start; //更新开始状态
}

void Raspberry_getstart(RASPBERRY *raspberry)
{
    raspberry->status.start = raspberry_temp.status.start; //获取开始状态
    //置位才清零标志位
    if(raspberry_temp.status.start == 1)
    {
        raspberry_temp.status.start = 0; //清零标志位
    }
}
