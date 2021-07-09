#include <stdio.h>
#include <string.h>

/*write a program to remove trailing blanks and tabs from each line of input
and delete entirely blank lines */
#define MAXLINE 10000

int getlines(char line[], int maxline);
int format(char line[]);
void main()
{
	int len;
	char line[MAXLINE];
	// line[0] = 'a';
	// line[1] = 'b';
	// int arraylen = strlen(line);
	// printf("string length is: %d", arraylen);

	while ((len = getlines(line, MAXLINE)) > 0)
	{
		// printf("string length is: %s", line);
		int formattedlen = format(line);
		printf("original length: %d,formatted length: %d:%s", len, formattedlen, line);
	}
}

int getlines(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

int format(char line[])
{
	int arraylen = strlen(line) + 1;
	int end = -1;
	int start = 0;

	for (int i = arraylen - 1; i >= 0; --i)
	{
		if (line[i] == '\n')
		{
			end = i;
		}

		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0')
		{
			start = i + 1;
			break;
		}
	}

	if (end != -1)
	{
		line[start] = '\n';
		line[start + 1] = '\0';
		return start + 1;
	}
	line[start + 1] = '\0';
	return start + 1;
}
