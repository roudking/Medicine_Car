#include "K210_uart.h"

#define BUFFER_SIZE 1000
unsigned char k210_cmd_buffer[BUFFER_SIZE]; //命令缓冲区
char k210_cmd[1000];


//树莓派串口中断初始化
void K210_uartinit(void)
{
//    usart_rx_it_start(K210_UART_INST_INT_IRQN);
}

// void K210_UART_INST_IRQHandler(void)
// {
// 			static int i = 0;
//             uint8_t k210_uctemp = usart_receivebyte(K210_UART);

// 	  if (k210_uctemp != '\n' && i < BUFFER_SIZE - 1) {
//             k210_cmd_buffer[i++] = k210_uctemp;
//         }
		 
// 	 else 
// 		{
// 			k210_cmd_buffer[i] = '\0'; // 完成字符串
// 			i = 0; // 重置索引
			
// 		   cJSON *json = cJSON_Parse((char *)k210_cmd_buffer);
		
// 		  if (json) {
// 				 cJSON *json_command = cJSON_GetObjectItem(json, "cmd");
		
// 			   if (json_command && json_command->type == cJSON_String) 
// 	  			{
//              strcpy(k210_cmd, json_command->valuestring); // 更新全局变量cmd
//   				if(strcmp(k210_cmd,"num") == 0)
// 				 {
//                     cJSON *num_json = cJSON_GetObjectItem(json, "result");
// 					char num_str[4];
// 					strcpy(num_str, num_json->valuestring);
// 					//将拿到的数字 一位一位存进num[2]
// 					int num[2] = {0, 0};
// 					int len = strlen(num_str);
// 					for (int i = 0; i < len; i++) {
// 						if (i < 2) {
// 							num[i] = num_str[i] - '0'; // 字符转数字
// 						}
// 					}

// 					  K210_numstatusIN(0);
//                     K210_numdataIN(num);
// 				}


// 				memset(k210_cmd_buffer,'\0',sizeof(k210_cmd_buffer));
// 				memset(k210_cmd,'\0',sizeof(k210_cmd));
// 		     }
//         }
// 	      cJSON_Delete(json);	
//       }
// }


