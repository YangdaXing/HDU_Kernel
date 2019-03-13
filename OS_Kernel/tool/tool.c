#include "tool.h"

/*
*该函数的作用是实现内存拷贝
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
*该函数的作用是将以dest为起始地址的内存区域的前n个字节设置为字符ch
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
乘除法函数
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
