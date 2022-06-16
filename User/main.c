/*
 * main.c
 *
 *	裸机程序
 *
 *  Created on: 2022-6-15
 *      Author: tly
 */

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "user_led.h"



 
 /*****************************************************************************
Function Name        :: int main(void)
Function Description :: 主函数
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
int main(void) 
{ 
 
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	
  /**下面是通过直接操作库函数的方式实现IO控制**/	
	
	while(1)
	{
		
		#if 0
			GPIO_ResetBits(GPIOF,GPIO_Pin_9);  //LED0对应引脚GPIOF.9拉低，亮  等同LED0=0;
			GPIO_SetBits(GPIOF,GPIO_Pin_10);   //LED1对应引脚GPIOF.10拉高，灭 等同LED1=1;
			delay_ms(500);  		   //延时300ms
			GPIO_SetBits(GPIOF,GPIO_Pin_9);	   //LED0对应引脚GPIOF.0拉高，灭  等同LED0=1;
			GPIO_ResetBits(GPIOF,GPIO_Pin_10); //LED1对应引脚GPIOF.10拉低，亮 等同LED1=0;
			delay_ms(500);                     //延时300ms
		#else
			LED1_ON;		  //LED0亮
			LED2_OFF;				//LED1灭
			delay_ms(500);
			LED1_OFF;				//LED0灭
			LED2_ON;				//LED1亮
			delay_ms(500);
		#endif
	}
}

/*******************下面注释掉的代码是通过 位带 操作实现IO口控制**************************************
	
int main(void)
{ 
 
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
  while(1)
	{
     LED0=0;			  //LED0亮
	   LED1=1;				//LED1灭
		 delay_ms(500);
		 LED0=1;				//LED0灭
		 LED1=0;				//LED1亮
		 delay_ms(500);
	 }
}
*/

