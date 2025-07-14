#include "K230_uart.h"

#define BUFFER_SIZE 1000
unsigned char k230_cmd_buffer[BUFFER_SIZE]; //命令缓冲区
char k230_cmd[1000];


//树莓派串口中断初始化
void K230_uartinit(void)
{
   usart_rx_it_start(K230_UART_INST_INT_IRQN);
}

void K230_UART_INST_IRQHandler(void)
{
			static int i = 0;
            uint8_t k230_uctemp = usart_receivebyte(K230_UART);

	  if (k230_uctemp != '\n' && i < BUFFER_SIZE - 1) {
            k230_cmd_buffer[i++] = k230_uctemp;
        }
		 
	 else 
		{
			k230_cmd_buffer[i] = '\0'; // 完成字符串
			i = 0; // 重置索引
			
		   cJSON *json = cJSON_Parse((char *)k230_cmd_buffer);
		
		  if (json) {
				 cJSON *json_command = cJSON_GetObjectItem(json, "cmd");
		
			   if (json_command && json_command->type == cJSON_String) 
	  			{
             strcpy(k230_cmd, json_command->valuestring); // 更新全局变量cmd
  				if(strcmp(k230_cmd,"pos") == 0)
				 {
                    cJSON *pos_json = cJSON_GetObjectItem(json, "result");
                    float pos = pos_json->valuedouble;
                    K230_posdataIN(pos);
				}
				else if(strcmp(k230_cmd,"tstatus") == 0)
				 {
					cJSON *Tstatus_json = cJSON_GetObjectItem(json, "result");
					int Tstatus;
					Tstatus = Tstatus_json->valueint;
					K230_tstatusIN(Tstatus);
				}
				else if(strcmp(k230_cmd,"nstatus") == 0)
				 {
					cJSON *Nstatus_json = cJSON_GetObjectItem(json, "result");
					int Nstatus;
					Nstatus = Nstatus_json->valueint;
					K230_nstatusIN(Nstatus);
				}

                


				memset(k230_cmd_buffer,'\0',sizeof(k230_cmd_buffer));
				memset(k230_cmd,'\0',sizeof(k230_cmd));
		     }
        }
	      cJSON_Delete(json);	
      }
}


