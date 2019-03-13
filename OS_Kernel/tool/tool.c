#include "tool.h"

/*
*�ú�����������ʵ���ڴ濽��
*/
void *memcpy(void *dest, void *src, int len)
{
	char *deststr = dest;
	char *srcstr = src;
	while (len--)
	{
		*deststr = *srcstr;
		++deststr;
		++srcstr;
	}
	return dest;
}

/*
*�ú����������ǽ���destΪ��ʼ��ַ���ڴ������ǰn���ֽ�����Ϊ�ַ�ch
*/
void *memset(void *dest, int ch, int n)
{
	char *deststr = dest;
	while (n--)
	{
		*deststr = ch;
		++deststr;
	}
	return dest;
}

/*
�˳�������
*/
int multiply(int a, int b)
{
	int res = 0;
	while (a != 0)
	{
		res += b;
		--a;
	}
	return res;
}

int division(int n, int div)
{
	int res = 0;
	while (n>div)
	{
		n -= div;
		++res;
	}
	return res;
}
