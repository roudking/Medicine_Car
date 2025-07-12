#include "Raspberry_Pi.h"

//树莓派缓存区
static RASPBERRY raspberry_temp;

void Raspberry_init(void)
{
   Raspberry_uartinit();
}

void Raspberry_leftspeeddataIN(int leftspeed)
{
    raspberry_temp.leftspeed = leftspeed;
}

void Raspberry_rightspeeddataIN(int rightspeed)
{
    raspberry_temp.rightspeed = rightspeed;
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

void Raspberry_keystatusIN(int status)
{
    raspberry_temp.status.key_status = status;
}

void Raspberry_getkeystatus(RASPBERRY *raspberry)
{
    raspberry->status.key_status = raspberry_temp.status.key_status;
    raspberry_temp.status.key_status = 0;
}

void Raspberry_resetstatusIN(int status)
{
     raspberry_temp.status.reset_status = status;
}

void Raspberry_getresetstatus(RASPBERRY *raspberry)
{
    raspberry->status.reset_status = raspberry_temp.status.reset_status;
    raspberry_temp.status.reset_status = 0;
}