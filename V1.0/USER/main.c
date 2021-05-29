#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

/*
u8 count;
u8 flag;

void USART1_IRQHandler(void)
{
    //u8 r;
 
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        USART_ClearITPendingBit(USART1, USART_IT_RXNE); //只USART_ReceiveData也可以
 
        //r = USART_ReceiveData(USART1);
 
        count++;
    }
    else if(USART_GetFlagStatus(USART1, USART_FLAG_IDLE) != RESET)
    {
        USART1->SR;
        USART1->DR;
 
        flag = 1;
    }
	}
*/

int main(void)
{
    LED_Init();
    delay_init();
    uart_init(9600);
		uart3_init(9600);
	
		
	 printf("test begins");
    while(1)
    {
				if(USART_GetITStatus(USART3,USART_IT_RXNE))   //若接收到数据
				{
					u8 Receive_Data = 0;
					Receive_Data = USART_ReceiveData(USART3);
					//printf("Now you see me");
					printf("Receive Succsed: %2x					\r\n", Receive_Data);
					USART_SendData(USART1,Receive_Data);
					if(Receive_Data == 0x61)
                LED0 = !LED0;
				}	else
        {
						delay_ms(1000);
            //printf("Now you");
            delay_ms(1000);
        }				
       //if(USART_GetITStatus(USART1, USART_IT_IDLE))
			 //{
//        if(USART_GetITStatus(USART1, USART_IT_RXNE))        //若接收到数据
//        {		
//						u8 Receive_Data = 0;
//            Receive_Data = USART_ReceiveData(USART1);        //读取数据后,RXNE标志位自动清零;
//            //printf("Receive Succsed: %c \r\n", Receive_Data);
//						//delay_ms(500);
//						printf("Now");
//						delay_ms(500);
//						USART_SendData(USART1,Receive_Data);
//						delay_ms(500);
//					if(Receive_Data == 0x61)
//                LED0 = !LED0;
//						//USART_ClearFlag(USART1,USART_IT_RXNE);        //手动清零
//        }
//        else
//        {
//						delay_ms(1000);
//            printf("Running....\r\n");

//        }
    }
	//}
}

/*
int main(void)
{
	 LED_Init();
   delay_init();
   uart_init(115200);
	
	 while(1)
    {
        if(flag == 1)
        {
            printf("count %d\r\n", count);
 
            flag = 0;
            count = 0;
        }
 
        delay_ms(10);
    }

}
*/