#include "Driver_pwm.h"

//初始化硬件pwm
void DriverPwm_start(DRIVER_CONFIG driver)
{
  pwm_init(driver.pwm_port);
}

//设置PWM
static void Driver_setonechannelpwm(DRIVER_CONFIG driver,int channel, int pwm)
{
    pwm_set(driver.pwm_port,driver.Channel[channel - 1],pwm);
}

// //滑行
// void Driver_setpwm(DRIVER_CONFIG driver,int pwm)
// {
// 	if (driver.Pwm_polarity == 0){
// 		if (pwm > 0) {
// 			Driver_setonechannelpwm(driver, 1, pwm);
// 			Driver_setonechannelpwm(driver, 2, 0);
// 		} else if (pwm < 0) {
// 			Driver_setonechannelpwm(driver, 1, 0);
// 			Driver_setonechannelpwm(driver, 2, -pwm);
// 		}
// 	} else if (driver.Pwm_polarity == 1) {
// 		if (pwm > 0) {
// 			Driver_setonechannelpwm(driver, 1, 0);
// 			Driver_setonechannelpwm(driver, 2, pwm);
// 		} else if (pwm < 0) {
// 			Driver_setonechannelpwm(driver, 1, -pwm);
// 			Driver_setonechannelpwm(driver, 2, 0);
// 		}
// 	}
// 	if (pwm == 0) {
// 		Driver_setonechannelpwm(driver, 1, 0);
// 		Driver_setonechannelpwm(driver, 2, 0);
// 	}
// }

//刹车
void Driver_setpwm(DRIVER_CONFIG driver,int pwm)
{
	if (driver.Pwm_polarity == 1) {
		if (pwm > 0) {
			Driver_setonechannelpwm(driver, 1, driver.DriverPWMTimer_autoreload - pwm);
			Driver_setonechannelpwm(driver, 2, driver.DriverPWMTimer_autoreload);
		} else if (pwm < 0) {
			Driver_setonechannelpwm(driver, 1, driver.DriverPWMTimer_autoreload);
			Driver_setonechannelpwm(driver, 2, driver.DriverPWMTimer_autoreload  + pwm);
		}
	} else if (driver.Pwm_polarity == 0) {
		if (pwm > 0) {
			Driver_setonechannelpwm(driver, 1, driver.DriverPWMTimer_autoreload);
			Driver_setonechannelpwm(driver, 2, driver.DriverPWMTimer_autoreload - pwm);
		} else if (pwm < 0) {
			Driver_setonechannelpwm(driver, 1, driver.DriverPWMTimer_autoreload  + pwm);
			Driver_setonechannelpwm(driver, 2, driver.DriverPWMTimer_autoreload);
		}
	}
	if (pwm == 0) {
		Driver_setonechannelpwm(driver, 1, driver.DriverPWMTimer_autoreload);
		Driver_setonechannelpwm(driver, 2, driver.DriverPWMTimer_autoreload);
	}
}



