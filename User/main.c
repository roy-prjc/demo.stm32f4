/*
 * main.c
 *
 *	�������
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
Function Description :: ������
Input Parameters     :: No
Return Value         :: No
Condition            :: No
Tips                 :: 
Function called	-

Last Chang Date      : 2022/06/15		
*****************************************************************************/
int main(void) 
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	
  /**������ͨ��ֱ�Ӳ����⺯���ķ�ʽʵ��IO����**/	
	
	while(1)
	{
		
		#if 0
			GPIO_ResetBits(GPIOF,GPIO_Pin_9);  //LED0��Ӧ����GPIOF.9���ͣ���  ��ͬLED0=0;
			GPIO_SetBits(GPIOF,GPIO_Pin_10);   //LED1��Ӧ����GPIOF.10���ߣ��� ��ͬLED1=1;
			delay_ms(500);  		   //��ʱ300ms
			GPIO_SetBits(GPIOF,GPIO_Pin_9);	   //LED0��Ӧ����GPIOF.0���ߣ���  ��ͬLED0=1;
			GPIO_ResetBits(GPIOF,GPIO_Pin_10); //LED1��Ӧ����GPIOF.10���ͣ��� ��ͬLED1=0;
			delay_ms(500);                     //��ʱ300ms
		#else
			LED1_ON;		  //LED0��
			LED2_OFF;				//LED1��
			delay_ms(500);
			LED1_OFF;				//LED0��
			LED2_ON;				//LED1��
			delay_ms(500);
		#endif
	}
}

/*******************����ע�͵��Ĵ�����ͨ�� λ�� ����ʵ��IO�ڿ���**************************************
	
int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
  while(1)
	{
     LED0=0;			  //LED0��
	   LED1=1;				//LED1��
		 delay_ms(500);
		 LED0=1;				//LED0��
		 LED1=0;				//LED1��
		 delay_ms(500);
	 }
}
*/

