#include "Raspberry_uart.h"

#define BUFFER_SIZE 1000
unsigned char raspberry_cmd_buffer[BUFFER_SIZE]; //命令缓冲区
char raspberry_cmd[1000];


//树莓派串口中断初始化
void Raspberry_uartinit(void)
{
   usart_rx_it_start(Raspberry_Pi_UART_INST_INT_IRQN);
}

void Raspberry_Pi_UART_INST_IRQHandler(void)
{
			static int i = 0;
            uint8_t raspberry_uctemp = usart_receivebyte(Raspberry_UART);

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
				else if(strcmp(raspberry_cmd,"mode") == 0)
				{ 
				  MODE mode;
				  cJSON *park_json = cJSON_GetObjectItem(json, "park");
			       mode.park = park_json->valuestring[0];
  
				  cJSON *target_json = cJSON_GetObjectItem(json, "target");
				   mode.target = target_json->valueint;

				  Raspberry_modedataIN(mode);
				  Raspberry_modedata_updateIN(1); //更新模式数据状态
			
				}
				else if(strcmp(raspberry_cmd,"run") == 0)
				{ 
			      Raspberry_runIN(1); //更新运行状态
				}
				else if(strcmp(raspberry_cmd,"start") == 0)
				{ 
				  Raspberry_startIN(1); //更新开始状态
				}



				memset(raspberry_cmd_buffer,'\0',sizeof(raspberry_cmd_buffer));
				memset(raspberry_cmd,'\0',sizeof(raspberry_cmd));
		     }
        }
	      cJSON_Delete(json);	
      }
}
