#ifndef _LCD_H
#define _LCD_H

#include "stm32f2xx.h"

/*******************************基础宏定义**************************************/
/*
画笔颜色
*/
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色

/*
*FSMC基础命令宏定义
*/
#define LCDcmd_SetCoordinateX 0x2A //设置列坐标
#define LCDcmd_SetCoordinateY 0x2B //设置行坐标

/*
*屏幕上半部分（13行）用于控制台的输入输出
*下半部分（2行）用于系统实时信息显示
*/
#define LCD_MAX_ROW 15
#define LCD_MAX_COL 40
#define LCD_TAB_LEN 4
#define LCD_ROW_SYSTEM 2
#define LCD_ROW_CONSOLE = (LCD_MAX_ROW - LCD_ROW_SYSTEM)
#define Row_PerMove 16
#define Col_PerMove 8

/***********************************全局变量*************************************/
extern uint16_t cursor_row;
extern uint16_t cursor_col;

/***********************************函数声明*************************************/
void init_LCD();
vu16 Delay_ms(vu16 count);
void LCD_IO_WriteReg(uint8_t Reg);
void LCD_IO_WriteData(uint16_t Data);
void LCD_DrawPoint(u16 x, u16 y, uint16_t GRB);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_OpenWindow(uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight);
void LCD_DrawArea(uint16_t usX, uint16_t usY, uint16_t usHeight, uint16_t usWidth, uint16_t GRB);
void putchar_single(uint16_t usX, uint16_t usY, u8 ch)//打印单个字符，字符点阵为16*8（16行*8列）SerialNumber是指字符在点阵数组中的起始位置
void put_char(u8 ch, int scope)//打印字符，自动维护位置


#endif // !_LCD_H

