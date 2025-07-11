#include "Raspberry_uart.h"

#define BUFFER_SIZE 1000
unsigned char raspberry_cmd_buffer[BUFFER_SIZE]; //命令缓冲区
char raspberry_cmd[1000];


//树莓派串口中断初始化
void Raspberry_uartinit(void)
{
   usart_rx_it_start(Debugger_UART_INST_INT_IRQN);
}

void Debugger_UART_INST_IRQHandler(void)
{
			static int i = 0;
            uint8_t raspberry_uctemp = usart_receivebyte(Debugger_UART_INST);

	  if (raspberry_uctemp != '\n' && i < BUFFER_SIZE - 1) {
            raspberry_cmd_buffer[i++] = raspberry_uctemp;
        }
		 
	 else 
		{
					raspberry_cmd_buffer[i] = '\0'; // 完成字符串
					i = 0; // 重置索引
			
		   cJSON *json = cJSON_Parse((char *)raspberry_cmd_buffer);
		
		  if (json) {
				 cJSON *json_command = cJSON_GetObjectItem(json, "cmd");
		
			   if (json_command && json_command->type == cJSON_String) 
	  			{
            strcpy(raspberry_cmd, json_command->valuestring); // 更新全局变量cmd
  				if(strcmp(raspberry_cmd,"ping") == 0)
				 {
					// 发送响应
					Raspberry_printf("{\"cmd\":\"ping\",\"result\":true}\n");
				}
				else if(strcmp(raspberry_cmd,"speed") == 0)
				{
					cJSON *leftspeed_json = cJSON_GetObjectItem(json, "l");
					cJSON *rightspeed_json = cJSON_GetObjectItem(json, "r");
							
			       
			    	int left_speed = leftspeed_json->valueint;
                    int right_speed = rightspeed_json->valueint;

                    
					Raspberry_leftspeeddataIN(left_speed);
                    Raspberry_rightspeeddataIN(right_speed);

				}
				else if(strcmp(raspberry_cmd,"angle") == 0)
				{
				  cJSON *angle_json = cJSON_GetObjectItem(json, "angle");
				  // 从 angle 中提取数字字符串
				  float angle = angle_json->valuedouble;
				  Raspberry_angledataIN(angle);

				 }
                 else if(strcmp(raspberry_cmd,"color") == 0)
                 {
                    cJSON *color_json = cJSON_GetObjectItem(json, "color");
                    char color = color_json->valuestring[0];  //潜在风险
                    Raspberr_colorIN(color);
                 }

				memset(raspberry_cmd_buffer,'\0',sizeof(raspberry_cmd_buffer));
				memset(raspberry_cmd,'\0',sizeof(raspberry_cmd));
		     }
        }
	      cJSON_Delete(json);	
      }
}


