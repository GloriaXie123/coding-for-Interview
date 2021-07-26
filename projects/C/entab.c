#include <stdio.h>
#define TABINC 8
/*
write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing.use the same tab stops as for detab,
when either a tab or a single space would suffice to reach a tab stop,which should
be given preference.
*/

main()
{
	int c, nt, nb, pos;
	nt = 0;
	nb = 0;
	for (pos = 1; (c = getchar()) != EOF; ++pos)
	{
		if (c == ' ')
		{
			++nb;
			if (pos % TABINC == 0)
			{
				++nt;
				nb = 0;
			}
		}
		else
		{
			for (; nt > 0; --nt)
			{
				// putchar('\t');
				printf("%s", "[\t]");
			}
			if (c == '\t')
			{
				// putchar('\t');
				printf("%s", "[\t]");
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
				nb = 0;
			}
			else
			{
				for (; nb > 0; --nb)
				{
					// putchar(' ');
					printf("%s", "[' ']");
				}
				if (c == '\n')
				{
					pos = 0;
				}
				// putchar(c);
				printf("%s", "[c]");
			}
		}
	}
	for (; nb > 0; --nb)
	{
		// putchar(' ');
		printf("%s", "[' ']");
	}
}
