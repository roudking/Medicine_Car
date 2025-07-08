#include "gpio_encoder.h"

//定义编码器数量
#define encoder_num 2
ENCODER_PORT encoder[encoder_num];

void encoder_init(int encoder_id,ENCODER_PORT encoder_port){
      encoder[encoder_id] = encoder_port;
}

void encoder_start(int encoder_id){
	 NVIC_EnableIRQ(encoder[encoder_id].IRQn);
}

int32_t encoder_getcounter(int encoder_id){
    int32_t counter = 0;
    counter = encoder[encoder_id].encoder_counter;
    encoder[encoder_id].encoder_counter = 0;
    return counter;
}

void GROUP1_IRQHandler(void){

  for(int i = 0; i < encoder_num; i++){
uint32_t encoder_itstatus = DL_GPIO_getEnabledInterruptStatus(encoder[i].gpio_port, encoder[i].EncoderA_PIN| encoder[i].EncoderB_PIN| encoder[i].EncoderC_PIN| encoder[i].EncoderD_PIN);

   if(encoder_itstatus & encoder[i].EncoderA_PIN)
   {
     if(DL_GPIO_readPins(encoder[i].gpio_port,encoder[i].EncoderC_PIN))
     {
         encoder[i].encoder_counter++;
     }
     else
     {
         encoder[i].encoder_counter--;
     }
     DL_GPIO_clearInterruptStatus(encoder[i].gpio_port,encoder[i].EncoderA_PIN);
   }


   else if(encoder_itstatus & encoder[i].EncoderB_PIN)
   {
     if(DL_GPIO_readPins(encoder[i].gpio_port,encoder[i].EncoderC_PIN))
     {
         encoder[i].encoder_counter--;
     }
     else
     {
         encoder[i].encoder_counter++;
     }
     DL_GPIO_clearInterruptStatus(encoder[i].gpio_port,encoder[i].EncoderB_PIN);
   }


   else if(encoder_itstatus & encoder[i].EncoderC_PIN)
   {
     if(DL_GPIO_readPins(encoder[i].gpio_port,encoder[i].EncoderA_PIN))
     {
        encoder[i].encoder_counter--;
     }
     else
     {
        encoder[i].encoder_counter++;
     }
     DL_GPIO_clearInterruptStatus(encoder[i].gpio_port,encoder[i].EncoderC_PIN);
   }


   else if(encoder_itstatus & encoder[i].EncoderD_PIN)
   {
     if(DL_GPIO_readPins(encoder[i].gpio_port,encoder[i].EncoderA_PIN))
     {
        encoder[i].encoder_counter++;
     }
     else
     {
        encoder[i].encoder_counter--;
     }
     DL_GPIO_clearInterruptStatus(encoder[i].gpio_port,encoder[i].EncoderD_PIN);
   }

  
   }
}
