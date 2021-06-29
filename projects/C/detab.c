#include <stdio.h>
/*write a program detab that replaces tabs in the input with proper number of blanks
to space to the next tab stop. Assumed a fixed set of tab stops,say every n columns, should
n be a variable or symbolic parameter*/
#define TABINC 16 //tab increment
main()
{
	int c, pos, nb;
	pos = 1;
	nb = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0)
			{
				putchar(' ');
				++pos;
				--nb;
			}
		}
		else if (c == '\n')
		{
			putchar(c);
			pos = 1;
		}
		else
		{
			putchar(c);
			++pos;
		}
	}
	return 0;
}
