#include <stdio.h>
#define MAXCOL 10
#define TABINC 8
/*write a program to 'fold' long input lines into two or more shorter lines 
after the last non-blank character that occurs before the n-th column of input,
make sure that your program does something intelligent with very long lines, and if
there are no blanks or tabs before the specified column.
*/
char line[MAXCOL]; /*input line*/

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void println(int pos);

/*fold long input lines into two or more shorter lines*/
void main()
{
	int c, pos;

	pos = 0;
	while ((c = getchar()) != EOF)
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
		else if (++pos >= MAXCOL - 1)
		{
			pos = findblnk(pos);
			println(pos);
			pos = newpos(pos);
		}
	}
}

void println(int pos)
{
	int i;
	for (i = 0; i < pos; ++i)
	{
		putchar(line[i]);
	}

	if (pos > 0)
	{
		putchar('\n');
	}
}

int exptab(int pos)
{
	line[pos] = ' ';
	for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
	{
		line[pos] = ' ';
	}
	if (pos < MAXCOL)
	{
		return pos;
	}
	else
	{
		println(pos);
		return 0;
	}
}

int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
	{
		--pos;
	}
	if (pos == 0)
	{
		return MAXCOL;
	}
	else
	{
		return pos + 1;
	}
}

int newpos(int pos)
{
	int i, j;

	if (pos <= 0 || pos >= MAXCOL)
	{
		return 0;
	}
	else
	{
		i = 0;
		for (j = pos + 1; j < MAXCOL; ++j)
		{
			line[i] = line[j];
			++i;
		}
	}
	return i;
}