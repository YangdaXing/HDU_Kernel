
#include "KeyBoard.h"


void init_KeyBoard()
{
	GPIO_InitTypeDef GPIO_InitStructure;
/*************************键盘初始化*****************************/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1; //ÁÐ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

/*****************************读取键盘返回button值*********************************************/
u8 Keyboard_Scan()
{
	u8 button = 255; //设定一个初值
/****************************拉低KEY5*****************************************/
	GPIO_ResetBits(GPIOE, GPIO_Pin_2);
	GPIO_SetBits(GPIOE, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0)
	{
		button = 15;
	}
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0) == 0)
	{
		button = 14;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0)
	{
		button = 13;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == 0)
	{
		button = 12;
	}

	/****************************拉低KEY6*****************************************/
	GPIO_ResetBits(GPIOE, GPIO_Pin_3);
	GPIO_SetBits(GPIOE, GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5);
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0)
	{
		button = 11;
	}
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0) == 0)
	{
		button = 10;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0)
	{
		button = 9;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == 0)
	{
		button = 8;
	}

	/****************************拉低KEY7*****************************************/
	GPIO_ResetBits(GPIOE, GPIO_Pin_4);
	GPIO_SetBits(GPIOE, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5);
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0)
	{
		button = 7;
	}
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0) == 0)
	{
		button = 6;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0)
	{
		button = 5;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == 0)
	{
		button = 4;
	}

	/****************************拉低KEY8*****************************************/
	GPIO_ResetBits(GPIOE, GPIO_Pin_5);
	GPIO_SetBits(GPIOE, GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4);
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_1) == 0)
	{
		button = 3;
	}
	if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0) == 0)
	{
		button = 2;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_6) == 0)
	{
		button = 1;
	}
	if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_3) == 0)
	{
		button = 0;
	}
	return button;
}

/*******************************键盘消抖**********************************************************/
u8 Keyboard_Jitter()
{
	u8 flag = 1;                  //用来判断10次读取的值是否一致
	u8 KeyValue = time_1ms();     //先存储第一次读取的键盘值
	for (int i = 1; i < 10; i++)  //核对10次
	{
		if (KeyValue != time_1ms())
		{
			flag = 0;
			break;
		}
	}
	if (flag)                     //如果匹配10次，则返回键盘输入值
	{
		return KeyValue;
	}
	else                          //如果未能匹配10次，则不返回
	{

	}
}

/*******************启动滴答计时器**********************************/
void Init_systick()
{
	SysTick->LOAD |= 0x00004650;//18000,相当于2ms定时
	SysTick->CTRL &= 0xfffffffb;//systick定时器配置时钟源 HCLK/8
	SysTick->CTRL |= 0x00000003;//启动滴答计时器，（以产生SysTick中断的方式）
}

void SysTick_Handler(void)
{
	u8 keyvalue = Keyboard_Scan();
}






/*存在的问题 读取函数不知道放在什么位置上比较好  返回值为255时表示未读取到键盘输入*/