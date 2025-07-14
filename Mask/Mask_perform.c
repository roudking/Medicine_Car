#include "Mask_perform.h"
#include "Car.h"


int Mask_performmask(CAR *car, MASK_ENUM mask_enum)
{
	  switch(mask_enum)
		{
			case wait_keyon:
					return Car_waitkeyonfuc(car);
			case wait_keyoff:
					return Car_waitkeyofffuc(car);
			case get_num:
					return Car_getnumfuc(car);
			case goto_T:
					return Car_gotoTfuc(car);
			// case go_over:
			// 		return Car_gooverfuc(car);
			case turnright:
					return Car_turnrightfuc(car);
			case turnleft:
					return Car_turnleftfuc(car);
			case turnback:
					return Car_turnbackfuc(car);
			case stop:
					return Car_stopfuc(car);
			default:
					return Car_stopfuc(car);
			    break;
				
		}

}

static int Mask_getmasknum(MASK mask)
{
    return sizeof(mask.mask_list)/sizeof(mask.mask_list[0]);
}

void Mask_setmask(CAR *car,MASK mask)
{
    car->mask = mask;
    car->mask.mask_num = Mask_getmasknum(mask);
}

void Mask_performmasks(CAR *car)
{
	static int cnt = 0;
	if(cnt < car->mask.mask_num)
	 {
		 int i = Mask_performmask(car,car->mask.mask_list[cnt]);
		  cnt = cnt + i;
	 }
	else
	 {
	   Mask_performmask(car,stop);
	 }		
}



