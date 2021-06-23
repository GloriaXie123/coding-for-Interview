#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

/*write a program to print a histogram of frequencies of different characters in its input*/
main()
{
	int c, i;
	int len;
	int maxvalue;
	int cc[MAXCHAR];

	for (int i = 0; i < MAXCHAR; ++i)
	{
		cc[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c < MAXCHAR)
		{
			++cc[c];
		}
	}

	maxvalue = 0;
	for (int i = 0; i < MAXCHAR; i++)
	{
		if (cc[i] > maxvalue)
		{
			maxvalue = cc[i];
		}
	}
	for (i = 1; i < MAXCHAR; i++)
	{
		if (cc[i] > 0 && cc[i] <= MAXHIST)
		{
			if (isprint(i))
			{
				printf("%5d - %c -%5d:", i, i, cc[i]);
			}
			else
			{
				printf("%5d -   -%5d:", i, cc[i]);
			}
			while (cc[i] > 0)
			{
				putchar('*');
				--cc[i];
			}
			putchar('\n');
		}
	}
	return 0;
}