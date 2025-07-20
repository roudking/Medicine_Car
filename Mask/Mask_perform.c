#include "Mask_perform.h"

int Mask_performmask(CAR *car, MASK_ENUM mask_enum)
{
	  switch(mask_enum)
		{
			case rled:
					return Car_rledfuc(car); break;
			case gled:
					return Car_gledfuc(car); break;
			case yled:
					return Car_yledfuc(car); break;
			case nled:
					return Car_nledfuc(car); break;
			case wait_keyon:
					return Car_waitkeyonfuc(car); break;
			case wait_keyoff:
					return Car_waitkeyofffuc(car); break;
			case get_num:
					return Car_getnumfuc(car); break;
			case goto_T:
					return Car_gotoTfuc(car); break;
			case goto_N:
					return Car_gotoNfuc(car); break;
			case go_over:
					return Car_gooverfuc(car); break;
			case turnright:
					return Car_turnrightfuc(car); break;	
			case turnleft:
					return Car_turnleftfuc(car); break;
			case turnback:
					return Car_turnbackfuc(car); break;
			case stop:
					return Car_stopfuc(car);
			case mask_load:
				    return Car_maskloadfuc(car); break;
			case echo_park:
					return Car_echoparkfuc(car); break;
			case wait_run:
					return Car_waitrunfuc(car); break;
			case get_mode:
					return Car_getmodefuc(car); break;
			case wait_start:
					return Car_waitstartfuc(car); break;
			default:
					return Car_stopfuc(car);
			    break;
				
		}

}


void Mask_performmasks(CAR *car)
{
	if(car->mask.mask_pc < car->mask.mask_num)
	 {
		if(car->mask.mask_list[car->mask.mask_pc] == mask_load)
			Mask_performmask(car,car->mask.mask_list[car->mask.mask_pc]);
		else	
		    car->mask.mask_pc += Mask_performmask(car,car->mask.mask_list[car->mask.mask_pc]);
	 }
	else
	 {
	   Mask_performmask(car,stop);
	 }		
}



