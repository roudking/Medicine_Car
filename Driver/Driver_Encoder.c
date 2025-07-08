#include "Driver_Encoder.h"


void DriverEncoder_init(DRIVER_CONFIG driver)
{
     encoder_init(driver.encoder_port.encoder_id, driver.encoder_port);
     encoder_start(driver.encoder_port.encoder_id);
}

int16_t DriverEncoder_getcounter(DRIVER_CONFIG driver)
{
    if (driver.Encoder_polarity == 1) {
        return encoder_getcounter(driver.encoder_port.encoder_id);
    }
    else {
        return -encoder_getcounter(driver.encoder_port.encoder_id);
    }

}
