#include <stdio.h>

#define MAXLENGTH 100
/*let's write a program to read a set of text lines and prints the longest one*/
int getlines(char line[], int upperlimit);
void copy(char to[], char from[]);

main()
{
	int len, longest;
	char currentline[MAXLENGTH];
	char longestchar[MAXLENGTH];

	longest = 0;

	while ((len = getlines(currentline, MAXLENGTH)) != 0)
	{
		if (len > longest)
		{
			longest = len;
			copy(longestchar, currentline);
		}
	}

	if (longest > 0)
	{
		printf("%s", longestchar);
	}
}

int getlines(char line[], int upperlimit)
{
	int c, i;

	for (i = 0; i < upperlimit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}
