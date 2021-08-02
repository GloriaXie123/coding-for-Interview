#include <stdio.h>

#define LINEMAX 20
#define TABINC 8

void println(int pos);
int exptab(int pos);
int findblnk(pos);
int newpos(pos);

char line[LINEMAX];
/*implement a word wraper to format lines*/
main()
{
	int c, pos;
	for (pos = 0; (c = getchar()) != EOF; ++pos)
	{
		line[pos] = c;
		if (c == '\t')
		{
			pos = exptab(pos);
		}
		else if (c == '\n')
		{
			println(pos);
			pos = 0;
		}
		else if (pos > LINEMAX - 2)
		{
			pos = findblnk(pos);
			println(pos);
			pos = newpos(pos);
		}
	}
}

int exptab(int pos)
{
	line[pos] = ' ';
	for (++pos; pos < LINEMAX && pos % TABINC != 0; ++pos)
	{
		line[pos] = ' ';
	}

	if (pos >= LINEMAX)
	{
		println(pos);
		pos = 0;
	}

	return pos;
}

void println(int pos)
{
	for (int i = 0; i < pos; ++i)
	{
		putchar(line[pos]);
	}
	if (pos > 0)
	{
		putchar('\n');
	}
}

int findblnk(int pos)
{
	for (; pos >= 0 && line[pos] == ' '; --pos)
		;

	if (pos < 0)
	{
		return LINEMAX;
	}
	else
	{
		return pos + 1;
	}
}

int newpos(int pos)
{
	int i, j;
	i = 0;
	j = pos + 1;
	for (; j < LINEMAX; ++j)
	{
		line[i] = line[j];
		++i;
	}

	return i;
}
