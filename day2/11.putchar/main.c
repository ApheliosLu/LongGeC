#include <stdio.h>
/* define some box-drawing characters */
#define LEFT_TOP 0xDA
#define RIGHT_TOP 0xBF
#define HORIZ 0xC4
#define VERT 0xB3
#define LEFT_BOT 0xC0
#define RIGHT_BOT 0xD9

int main(void)
{
	char i, j;
	/* draw the top of the box */
	putchar(LEFT_TOP);
	for (i = 0; i < 10; i++)
	{
		putchar(HORIZ);
		putchar(RIGHT_TOP);
		putchar('\n');
	}

	/* draw the middle */
	for (i = 0; i < 4; i++)
		putchar(VERT);
	for (j = 0; j < 10; j++)
	{
		putchar(' ');
		putchar(VERT);
		putchar('\n');
		/* draw the bottom */
		putchar(LEFT_BOT);
	}
	for (i = 0; i < 10; i++)
	{
		putchar(HORIZ);
		putchar(RIGHT_BOT);
		putchar('\n');
		return 0;
	}
}