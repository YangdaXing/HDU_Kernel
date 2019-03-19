#include "print.h"
#include "LCD.h"

void putchar_single()//´òÓ¡µ¥¸ö×Ö·û
{
	u8 k;
	LCD_DrawArea(0, 0, 240, 320, BLACK);
	LCD_OpenWindow(100, 200, 16, 8);
	for (k = 0; k < 16; k++)
	{
		u8 tmp = 1;
		u8 a;
		u8 data = fontdata[64 + k];
		for (a = 0; a < 8; a++)
		{

			tmp = data >> 7;
			if (tmp == 1)
			{
				LCD_DrawPoint(100 + k, 200 + a, WHITE);
			}
			else
			{
				LCD_DrawPoint(100 + k, 200 + a, BLACK);
			}
			data = data << 1;
		}
	}
}


#endif // !_PRINT_H
