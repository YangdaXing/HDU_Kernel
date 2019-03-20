#ifndef _LCD_H
#define _LCD_H

#include "stm32f2xx.h"

/*******************************�����궨��**************************************/
/*
������ɫ
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
#define BROWN 			 0XBC40 //��ɫ
#define BRRED 			 0XFC07 //�غ�ɫ
#define GRAY  			 0X8430 //��ɫ

/*
*FSMC��������궨��
*/
#define LCDcmd_SetCoordinateX 0x2A //����������
#define LCDcmd_SetCoordinateY 0x2B //����������

/*
*��Ļ�ϰ벿�֣�13�У����ڿ���̨���������
*�°벿�֣�2�У�����ϵͳʵʱ��Ϣ��ʾ
*/
#define LCD_MAX_ROW 15
#define LCD_MAX_COL 40

#define LCD_ROW_SYSTEM 2
#define LCD_ROW_CONSOLE = (LCD_MAX_ROW - LCD_ROW_SYSTEM)
#define Row_PerMove 16
#define Col_PerMove 8

/***********************************ȫ�ֱ���*************************************/
extern uint16_t cursor_row;
extern uint16_t cursor_rol;

/***********************************��������*************************************/
void init_LCD();
vu16 Delay_ms(vu16 count);
void LCD_IO_WriteReg(uint8_t Reg);
void LCD_IO_WriteData(uint16_t Data);
void LCD_DrawPoint(u16 x, u16 y, uint16_t GRB);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_OpenWindow(uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight);
void LCD_DrawArea(uint16_t usX, uint16_t usY, uint16_t usHeight, uint16_t usWidth, uint16_t GRB);



#endif // !_LCD_H

