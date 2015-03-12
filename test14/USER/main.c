#pragma once
#include "stm32f10x.h"
#include "usart1.h"
#include "SysTick.h"
#include "usart2.h"
#include "misc.h"
#include "IIC.h"
#include "led.h"
#include "getdata.h"
int main(void)
{
	/* ����2��ʼ�� */
//	USART1_Config();
	USART2_Config();
//	NVIC_Configuration();
    NVIC_Configuration1();
	/* ����SysTick Ϊ1us�ж�һ�� */
	SysTick_Init();	
	 
	/* Init I2C and MPU6050*/
  	i2cInit();
	LED_GPIO_Config();
	if (mpuDMPinit())
	{
		// dmp�豸��ʼ��ʧ��
		printf("f");
	}
	// dmp�豸��ʼ���ɹ�
	else printf("i");		
	// ����㷨
	checkAlgo();
	return 0; 
}
