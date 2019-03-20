#include "LCD.h"

/***********************************初始化LCD屏幕**********************************/
void init_LCD()
{
	/*******************************全局变量定义***********************************/
	GPIO_InitTypeDef GPIO_InitStructure;
	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef  p;
	/* Enable GPIOs clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOC, ENABLE);

	/* Enable FSMC clock */
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

	/********************************首先设置LCD的RST位*****************************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //PC0推挽输出 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 		 //推挽谁出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_SetBits(GPIOD, GPIO_Pin_12);

	/********************************设置LCD的LCD_BL位***********************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //PC0 推挽输出 背光
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 		 //推挽输出
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_0);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);
	//GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 |
		GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* GPIOE configuration */
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FSMC);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |
		GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

	GPIO_Init(GPIOE, &GPIO_InitStructure);

	/*-- FSMC Configuration ------------------------------------------------------*/
	p.FSMC_AddressSetupTime = 6;
	p.FSMC_AddressHoldTime = 1;
	p.FSMC_DataSetupTime = 9;
	p.FSMC_BusTurnAroundDuration = 1;
	p.FSMC_CLKDivision = 0;
	p.FSMC_DataLatency = 0;
	p.FSMC_AccessMode = FSMC_AccessMode_A;

	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);

	/*!< Enable FSMC Bank1_SRAM1 Bank */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
	Delay_ms(200);
	GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	Delay_ms(500);
	GPIO_SetBits(GPIOD, GPIO_Pin_12);
	Delay_ms(500);
	Delay_ms(50); 					// delay 50 ms 
	LCD_IO_WriteReg(0xCF);  //这段代码是用来设置LCD横屏竖屏显示方式，即x,y坐标
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0xC1);
	LCD_IO_WriteData(0X30);
	LCD_IO_WriteReg(0xED);
	LCD_IO_WriteData(0x64);
	LCD_IO_WriteData(0x03);
	LCD_IO_WriteData(0X12);
	LCD_IO_WriteData(0X81);
	LCD_IO_WriteReg(0xE8);
	LCD_IO_WriteData(0x85);
	LCD_IO_WriteData(0x10);
	LCD_IO_WriteData(0x7A);
	LCD_IO_WriteReg(0xCB);
	LCD_IO_WriteData(0x39);
	LCD_IO_WriteData(0x2C);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x34);
	LCD_IO_WriteData(0x02);
	LCD_IO_WriteReg(0xF7);
	LCD_IO_WriteData(0x20);
	LCD_IO_WriteReg(0xEA);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(0xC0);    //Power control 
	LCD_IO_WriteData(0x1B);   //VRH[5:0] 
	LCD_IO_WriteReg(0xC1);    //Power control 
	LCD_IO_WriteData(0x01);   //SAP[2:0];BT[3:0] 
	LCD_IO_WriteReg(0xC5);    //VCM control 
	LCD_IO_WriteData(0x30); 	 //3F
	LCD_IO_WriteData(0x30); 	 //3C
	LCD_IO_WriteReg(0xC7);    //VCM control2 
	LCD_IO_WriteData(0XB7);
	LCD_IO_WriteReg(0x36);    // Memory Access Control 
	LCD_IO_WriteData(0x48);
	LCD_IO_WriteReg(0x3A);
	LCD_IO_WriteData(0x55);
	LCD_IO_WriteReg(0xB1);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x1A);
	LCD_IO_WriteReg(0xB6);    // Display Function Control 
	LCD_IO_WriteData(0x0A);
	LCD_IO_WriteData(0xA2);
	LCD_IO_WriteReg(0xF2);    // 3Gamma Function Disable 
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(0x26);    //Gamma curve selected 
	LCD_IO_WriteData(0x01);
	LCD_IO_WriteReg(0xE0);    //Set Gamma 
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteData(0x2A);
	LCD_IO_WriteData(0x28);
	LCD_IO_WriteData(0x08);
	LCD_IO_WriteData(0x0E);
	LCD_IO_WriteData(0x08);
	LCD_IO_WriteData(0x54);
	LCD_IO_WriteData(0XA9);
	LCD_IO_WriteData(0x43);
	LCD_IO_WriteData(0x0A);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteReg(0XE1);    //Set Gamma 
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x15);
	LCD_IO_WriteData(0x17);
	LCD_IO_WriteData(0x07);
	LCD_IO_WriteData(0x11);
	LCD_IO_WriteData(0x06);
	LCD_IO_WriteData(0x2B);
	LCD_IO_WriteData(0x56);
	LCD_IO_WriteData(0x3C);
	LCD_IO_WriteData(0x05);
	LCD_IO_WriteData(0x10);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteData(0x3F);
	LCD_IO_WriteData(0x3F);
	LCD_IO_WriteData(0x0F);
	LCD_IO_WriteReg(0x2B);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x01);
	LCD_IO_WriteData(0x3f);
	LCD_IO_WriteReg(0x2A);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0x00);
	LCD_IO_WriteData(0xef);
	LCD_IO_WriteReg(0x11); //Exit Sleep
	Delay_ms(120);
	LCD_IO_WriteReg(0x29); //display on
	/********************************************************************************/
}

/***********************************粗延时函数*************************************/
vu16 Delay_ms(vu16 Count)
{
	u16 i = 0;
	while (Count--)
	{
		for (i = 12000; i > 0; i--);
	}
	return Count;
}

/***********************************写指令函数**************************************/
void LCD_IO_WriteReg(uint8_t Reg)
{
	/* Write 16-bit Index, then Write Reg */
	*(__IO uint16_t *)FSMC_LCD_REG = Reg;
}

/***********************************写数据函数*************************************/
void LCD_IO_WriteData(uint16_t Data)
{
	/* Write 16-bit Reg */
	*(__IO uint16_t *)FSMC_LCD_DATA = Data;
}

/***********************************选定区域函数*************************************/
void LCD_OpenWindow(uint16_t usX, uint16_t usY,uint16_t usWidth,uint16_t usHeight) //默认原点坐标是右下角，现在设置为左上角，Y轴为水平向左，X轴为竖直向下
{
	LCD_IO_WriteReg(LCDcmd_SetCoordinateX);//设置行
	LCD_IO_WriteData((239 - usX - usWidth + 1) >> 8);
	LCD_IO_WriteData((239 - usX - usWidth + 1) & 0xff);
	LCD_IO_WriteData((239 - usX) >> 8);
	LCD_IO_WriteData(239 - usX & 0XFF);


	LCD_IO_WriteReg(LCDcmd_SetCoordinateY); //设置列

	LCD_IO_WriteData((319 - usY - usHeight + 1) >> 8);
	LCD_IO_WriteData((319 - usY - usHeight + 1) & 0xff);
	LCD_IO_WriteData((319 - usY) >> 8);
	LCD_IO_WriteData(319 - usY & 0XFF);

}

/***********************************设置光标函数**********************************************/
void LCD_SetCursor(uint16_t row, uint16_t col)
{
	//如何使光标闪烁？
	cursor_row = row;
	cursor_rol = col;
}

/************************************打点函数***********************************************/
void LCD_DrawPoint(u16 usX, u16 usY, uint16_t GRB)
{

	LCD_OpenWindow(usX, usY, 1, 1);
	LCD_IO_WriteReg(0x2C); 	//?????
	LCD_IO_WriteData(GRB);
}

/***********************************大面积涂色函数**********************************************/
void LCD_DrawArea(uint16_t usX, uint16_t usY, uint16_t usHeight, uint16_t usWidth, uint16_t GRB)
{
	uint16_t i, j;
	for (i = 0; i < usHeight; i++)
	{
		for (j = 0; j < usWidth; j++)
		{
			LCD_DrawPoint(usX + i, usY + j, GRB);               //????????
		}
	}
}

/************************************清屏函数********************************************/
void LCD_CleanScreen(uint16_t scope)
{
	uint16_t r, c;                       //控制光标所在位置
	uint32_t row_sum = scope * Row_PerMove;       //一共需要清除的x方向的最大值
	uint32_t col_sum = LCD_MAX_COL * Col_PerMove;  //一共需要清除的y方向的最大值
	for ( r = 0; r < row_sum; r++)
	{
		for ( c = 0; c < col_sum; c++)
		{
			LCD_DrawPoint(r, c, BLACK);  //将要清屏的位置涂成黑色
		}
	}
	LCD_SetCursor(0, 0);                 //将光标置于起始位置
}

/**********************************在指定位置打印相应字符************************************************/
void putchar_single(uint16_t usX, uint16_t usY, u8 ch)//打印单个字符，字符点阵为16*8（16行*8列）SerialNumber是指字符在点阵数组中的起始位置
{
	u8 row;
	//LCD_DrawArea(0, 0, 240, 320, BLACK);
	for (row = 0; row < 16; row++)//控制行输出
	{
		u8 tmp = 1;         //用来临时储存字符点阵移位的一位值
		u8 col;
		uint32_t SerialNumber = ('ch' - 32) * 16;//计算ch的点阵在数组中的位置
		u8 data = fontdata[SerialNumber + row];
		for (col = 0; col < 8; col++)//控制列输出
		{
			tmp = data >> 7;//点阵一行的最高位值
			if (tmp == 1)
			{
				LCD_DrawPoint(usX + row, usY + col, WHITE);
			}
			else
			{
				LCD_DrawPoint(usX + row, usY + col, BLACK);
			}
			data = data << 1;//将点阵移位，读取次位值
		}
	}
}

/***************************************打印一个字符，自动维护光标位置*********************************************************/
void put_char(u8 ch, uint16_t scope)
{
	if (ch == '\n')                 //如果匹配到换行符
	{
		cursor_col = 0;
		cursor_row += Row_PerMove;
		if (cursor_row==scope*Row_PerMove)
		{
			LCD_CleanScreen(scope);
		}
		else
		{
			LCD_SetCursor(cursor_row, cursor_col);
		}
		return;
	}
	if (ch == '\t')
	{
		cursor_col = LCD_TAB_LEN * Col_PerMove;
		if (cursor_col >= LCD_MAX_COL*Col_PerMove)
		{
			cursor_col = 0;
			cursor_row += Row_PerMove;
		}
		if (cursor_row == scope * Row_PerMove)
		{
			LCD_CleanScreen(scope);
		}
		else
		{
			LCD_SetCursor(cursor_row, cursor_col);
		}
		return;
	}
	putchar_single(cursor_row, cursor_col, ch);
	cursor_col += Col_PerMove;
	if (cursor_col >= LCD_MAX_COL * Col_PerMove)
	{
		cursor_col = 0;
		cursor_row += Row_PerMove;
	}
	if (cursor_row == scope * Row_PerMove)
	{
		LCD_CleanScreen(scope);
	}
	else
	{
		LCD_SetCursor(cursor_row, cursor_col);
	}
}

/*
*!!!主要问题，如何是坐标的计算以 16*8 为一个单位，而不是 点*点 为单位，这样在后续的操作会带来麻烦
*/


