#include <stdio.h>

/*revise the main routine of the longest-line program,so it will 
correctly print the length of arbitrary long input lines,
and as much as possible of the text*/
#define MAXLENGTH 10

int getlines(char line[], int maxline);
void copy(char max[], char line[]);
main()
{
	int len, maxlen;
	char line[MAXLENGTH], max[MAXLENGTH];

	maxlen = 0;
	while ((len = getlines(line, MAXLENGTH)) > 0)
	{
		printf("%d, %s", len, line);
		if (len > maxlen)
		{
			maxlen = len;
			copy(max, line);
		}
	}

	if (maxlen > 0)
	{
		printf("%d,%s", maxlen, max);
	}

	return 0;
}

int getlines(char line[], int maxline)
{
	int c, i, j;
	j = 0;
	for (i = 0; (c = getchar()) != EOF; ++i)
	{
		if (i < maxline - 1)
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

void copy(char max[], char line[])
{
	int i;
	i = 0;
	while ((max[i] = line[i]) != '\0')
	{
		++i;
	}
}
