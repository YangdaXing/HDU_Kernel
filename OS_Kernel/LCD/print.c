#include "print.h"
#include "LCD.h"

/**********************************在指定位置打印相应字符************************************************/
void putchar_single(uint16_t usX,uint16_t usY,u8 ch)//打印单个字符，字符点阵为16*8（16行*8列）SerialNumber是指字符在点阵数组中的起始位置
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

/*
*!!!主要问题，如何是坐标的计算以 16*8 为一个单位，而不是 点*点 为单位，这样在后续的操作会带来麻烦
*现在还需要3个函数，
*1、一个是打印一个字符，光标移动一个位置
*2、判断是否到了边界，到了边界自动换行
*3、清屏函数，滚动函数
*除此之外，还需要建立ASCII点阵和字符序号一一对应，从而可以控制输出，需要先识别查找SerialNumber，再输出在屏幕上
*/




