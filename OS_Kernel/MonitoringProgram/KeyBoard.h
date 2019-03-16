#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "stm32f2xx.h"

/*
*全局变量
*/
extern u8 KeyValue;//对外输出变量
static u8 keyvalue_tmp;//函数内部使用变量，临时储存键值


/*
*函数声明
*/
void init_keyboard();      //初始化键盘
u8 time_1ms();              //利用systick计时1ms
u8 Keyboard_Scan();              //键盘扫描函数
u8 Keyboard_Jitter();          //键盘消抖函数

#endif // !_KEYBOARD_H

