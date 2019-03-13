#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "stm32f2xx.h"

void init_keyboard();      //
u8 time_1ms();              //利用systick计时1ms
u8 Keyboard_Scan();              //键盘扫描函数
u8 Keyboard_Jitter();          //键盘消抖函数

#endif // !_KEYBOARD_H

