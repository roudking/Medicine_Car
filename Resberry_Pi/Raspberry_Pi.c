#include "Raspberry_Pi.h"

static RASPBERRY_TEMP raspberry_temp;

void Raspberry_init(void)
{
   Raspberry_uartinit();
}

void Raspberry_speeddataIN(int indata)
{
   raspberry_temp.speed = indata;
}

void Raspberry_getspeed(RASPBERRY *raspberry)
{
	raspberry->speed = raspberry_temp.speed;
}

void Raspberry_angledataIN(double angle)
{
   raspberry_temp.angle = angle;
}

void Raspberry_getangle(RASPBERRY *raspberry)
{
	raspberry->angle = raspberry_temp.angle;
}

void Raspberry_stateIN(Raspberry_STATE state)
{
   raspberry_temp.state = state;
}   

void Raspberry_getstate(RASPBERRY *raspberry)
{
	raspberry->state = raspberry_temp.state;
}

