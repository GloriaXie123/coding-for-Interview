#include <stdio.h>

/*revise the main routine of the longest-line program,so it will 
correctly print the length of arbitrary long input lines,
and as much as possible of the text*/
#define MAXLENGTH 10

int getlines(char line[], int maxline);
void copy(char max[], char line[]);
main()
{
	int linelen, maxlinelen;
	char line[MAXLENGTH], max[MAXLENGTH];

	maxlinelen = 0;
	while ((linelen = getlines(line, MAXLENGTH)) > 0)
	{
		printf("%d, %s", linelen, line);
		if (linelen > maxlinelen)
		{
			maxlinelen = linelen;
			copy(max, line);
		}
	}

	if (maxlinelen > 0)
	{
		printf("%d,%s", maxlinelen, max);
	}

	return 0;
}

int getlines(char line[], int maxline)
{
	int c, i, j;
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < maxline - 2)
		{
			line[j] = c;
			++j;
		}
	}
	if (c == '\n')
	{
		line[j] = c;
		++i;
		++j;
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
