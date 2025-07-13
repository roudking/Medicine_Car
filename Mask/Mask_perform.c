#include "Mask_perform.h"
#include "Car.h"


int Mask_performask(CAR *car, MASK_ENUM mask_enum)
{
	  switch(mask_enum)
		{
			case wait_start:
					return Car_waitstartfuc(car);
					break;
			case goto_line:
				  return Car_gotolinefuc(car);
					break;
			case goto_turnright:
				  return Car_gototurnrightfuc(car);
					break;
			case goto_turnleft:
				  return Car_gototurnleftfuc(car);
					break;
			case go_strightoverflow:
					return Car_gostrightoverflowfuc(car);
					break;
			case turnright:
					return Car_turnrightfuc(car);
					break;
			case turnleft:
					return Car_turnleftfuc(car);
					break;
			case beep:
					return Car_beepfuc(car);
					break;
			case stop:
					return Car_stopfuc(car);
					break;
			case go_avoidance:
				  return Car_goavoidance(car);
				  break;
			case gobackto_line:
				  return Car_gobacktolinefuc(car);
				  break;
			case goto_allwhite:
				  return Car_gotoallwhitefuc(car);
				  break;
			case getnum:
				  return Car_getnumberfuc(car);
				  break;
			case turnleftto_line:
				  return Car_turnlefttolinefuc(car);
				  break;
			case gountil_end:
				  return Car_gountilend(car);
				  break;
			case turnto_end:
				  return Car_turntoend(car);
				  break;
			case resethwt101:
					return Car_resethwt101fuc(car);
				  break;		
			case voice_trace:
					return Car_voicetrance(car);
				  break;		
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



