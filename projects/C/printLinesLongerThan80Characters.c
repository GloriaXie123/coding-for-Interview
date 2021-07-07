#include <stdio.h>

#define MAXLENGTH 100
/*write a program to print all input lines that longer than 80 characters*/

int getlines(char line[], int maxlength);
main()
{
	int len, maxlen;
	char line[MAXLENGTH];
	while ((len = getlines(line, MAXLENGTH)) > 0)
	{
		if (len > 80)
		{
			printf("%s", line);
		}
	}
}

int getlines(char line[], int maxlength)
{
	int i, j, c;
	j = 0;
	for (i = 0; (c = getchar()) != EOF; ++i)
	{
		if (i < maxlength - 1)
		{
			line[j] = c;
			++j;
		}
		if (c == '\n')
		{
			++i;
			break;
		}
	}
	line[j] = '\0';
	return i;
}
