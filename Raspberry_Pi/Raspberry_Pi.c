#include "Raspberry_Pi.h"

//树莓派缓存区
static RASPBERRY_TEMP raspberry_temp;

void Raspberry_init(void)
{
   Raspberry_uartinit();
}

void Raspberry_leftspeeddataIN(int indata)
{
    raspberry_temp.leftspeed = indata;
}

void Raspberry_rightspeeddataIN(int indata)
{
    raspberry_temp.rightspeed = indata;
}

void Raspberry_getleftspeed(RASPBERRY *raspberry)
{
	raspberry->leftspeed = raspberry_temp.leftspeed;
}

void Raspberry_getrightspeed(RASPBERRY *raspberry)
{
    raspberry->rightspeed = raspberry_temp.rightspeed;
}

void Raspberry_angledataIN(float angle)
{
   raspberry_temp.angle = angle;
}

void Raspberry_getangle(RASPBERRY *raspberry)
{
	raspberry->angle = raspberry_temp.angle;
    raspberry_temp.angle = 0; //清空缓存
}

void Raspberr_colorIN(char color)
{
    raspberry_temp.led_color = color;
}

void Raspberry_getcolor(RASPBERRY *raspberry)
{
    raspberry->led_color = raspberry_temp.led_color;
}

void Raspberry_askstatusIN(int askstatus)
{
     raspberry_temp.keyask_status = askstatus;
}

void Raspberry_getaskstatus(RASPBERRY *raspberry)
{
    raspberry->keyask_status = raspberry_temp.keyask_status;
    raspberry_temp.keyask_status = 0;
}

void Raspberry_stateIN(Raspberry_STATE state)
{
   raspberry_temp.state = state;
}   

void Raspberry_getstate(RASPBERRY *raspberry)
{
	raspberry->state = raspberry_temp.state;
}

