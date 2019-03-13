#ifndef _LCD_H
#define _LCD_H

#include "stm32f2xx.h"

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

/***********************************函数声明*************************************/
void init_LCD();
vu16 Delay_ms(vu16 count);
void LCD_IO_WriteReg(uint8_t Reg);
void LCD_IO_WriteData(uint16_t Data);
void LCD_DrawPoint(u16 x, u16 y, uint16_t GRB);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_Color_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t GRB);



#endif // !_LCD_H

