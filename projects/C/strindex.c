#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define NFOUND -1
/*write a function strindex(s,t),which returns the occurrence of 
rightmost position of t in s, returns -1 if none is found.*/
char pattern[MAXLINE] = "ould";

int getlines(char line[]);
int strindex(char line[], char pattern[]);

void main()
{
	char line[MAXLINE];
	while (getlines(line) > 0)
	{
		if (strindex(line, pattern) >= 0)
		{
			printf("%s", line);
		}
	}
}

int getlines(char line[])
{
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		line[i++] = c;
	}
	if (c == '\n')
	{
		line[i++] = c;
	}
	line[i] = '\0';
	return i;
}

int strindex(char line[], char pattern[])
{
	int i, j;
	i = j = 0;
	while (line[i] != pattern[j] && line[i] != '\0')
	{
		++i;
	}

	if (line[i] == '\0')
	{
		return NFOUND;
	}

	while (pattern[j] != '\0' && line[i] != '\0')
	{
		if (line[i++] != pattern[j++])
		{
			return NFOUND;
		}
	}

	if (j < strlen(pattern))
	{
		return NFOUND;
	}
	else
	{
		return j;
	}
}
