#include "print.h"
#include "LCD.h"

void putchar_single()
{
	LCD_DrawArea(239,319,)
	u8 tmp;
	for (u8 k = 0; k < 16; k++)
	{
		tmp = fontdata[16 + k] >> 7;
		if (tmp == 1)
		{
			LCD_DrawPoint(0)
		}
		else
		{
			continue;
		}
	}

}


#endif // !_PRINT_H
