/******************** (C) COPYRIGHT 2012 WildFire Team ***************************
 * �ļ���  ��led.c
 * ����    ��led Ӧ�ú�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * Ӳ�����ӣ�-----------------
 *          |   PC3 - LED1     |
 *          |   PC4 - LED2     |
 *          |   PC5 - LED3     |
 *           ----------------- 
 * ��汾  ��ST3.5.0
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "led.h"

/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����GPIOC������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOC*/
  	GPIO_Init(GPIOC, &GPIO_InitStructure);		  

	/* �ر�����led��	*/
	GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);	 
}
void LED_toggle(int led)
{
	if (led == 1)
	{
		if( 1 == GPIO_ReadOutputDataBit  ( GPIOC, GPIO_Pin_3) )
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_3);	
		}
		else
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_3);
		}

	}
	else if (led == 2)
	{
		if( 1 == GPIO_ReadOutputDataBit  ( GPIOC, GPIO_Pin_4) )
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_4);	
		}
		else
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_4);
		}
	}
	else if(led == 3)
	{
		if( 1 == GPIO_ReadOutputDataBit  ( GPIOC, GPIO_Pin_5) )
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_5);	
		}
		else
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_5);
		}	
	}
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/