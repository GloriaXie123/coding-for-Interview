#include <stdio.h>

/*Modify getnext so that it doesn't need to use ungetch, Hint: use an internal
static variable*/

int getnext(char s[])
{
	static int backup;
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{
		return c;
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';
	if (c != EOF)
	{
		backup = c;
	}
	return NUM;
}
