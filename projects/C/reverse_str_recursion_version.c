#include <stdio.h>
#include <string.h>

#define MAXVAL 100
/*write a function reverse(s) that reverses the character string s,
use it to write a program to reverses its input a line at a time*/
int getlines(char[], int MAXVAL);
void reverse(char[], int low, int high);
void swap(char *s, int a, int b);

main()
{
	int len;
	char line[MAXVAL];
	if (len = getlines(line) > 0)
	{
		reverse(line, 0, len - 1);
		printf("%s", s);
	}
}

int getlines(char line[], MAXVAL)
{
	int i, c;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < MAXVAL - 1)
	{
		line[i] = c;
		++i;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void reverse(char line[], int low, int high)
{
	int i, j;
	i = low;
	j = high;

	while (i < j)
	{
		reverse(++i, --j);
	}

	swap(line, line[--i], line[++j]);
}

void swap(char *s, int a, int b)
{
	char temp;
	temp = *(s + a);
	*(s + a) = *(s + b);
	*(s + b) = temp;
}
