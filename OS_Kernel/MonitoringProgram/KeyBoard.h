#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include "stm32f2xx.h"

/*
*ȫ�ֱ���
*/
extern u8 KeyValue;//�����������
static u8 keyvalue_tmp;//�����ڲ�ʹ�ñ�������ʱ�����ֵ
static u8 keyvalue;//���ڴ洢ǰ������ͬ��ɨ����
static u8 Counter;//���ڼ���

/*
*��������
*/
void init_KeyBoard();      //��ʼ������
u8 Keyboard_Scan();              //����ɨ�躯��
u8 Keyboard_Jitter();          //������������

#endif // !_KEYBOARD_H

