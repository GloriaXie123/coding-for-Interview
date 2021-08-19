#include <stdio.h>

#define MAX 100

/*write a function reverse(s) that reverses the character string s,
use it to write a program to reverses its input a line at a time*/
int getinputline(char[], int limit);
void reverse(char[], int low, int high);
void swap(char *s, int a, int b);

void main()
{
	int len;
	char line[MAX];
	if ((len = getinputline(line, MAX)) > 0)
	{
		reverse(line, 0, len - 1);
		printf("%s", line);
	}
}

int getinputline(char line[], int limit)
{
	int i, c;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < MAX - 1)
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
	j = (line[high] == '\n') ? --high : high;

	while (i < j)
	{
		reverse(line, ++i, --j);
	}

	swap(line, i, j);
}

void swap(char *s, int a, int b)
{
	char temp;
	temp = *(s + b);
	*(s + b) = *(s + a);
	printf("%s", s);
	*(s + a) = temp;
	printf("%s", s);
}
