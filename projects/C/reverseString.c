#include <stdio.h>
#include <string.h>

/*write a function reverse(s) that reverses the character string s,
use it to write a program to reverses its input a line at a time*/
#define LIMIT 1000
void reverse(char s[], int arraylen);
void swap(char *s, int a, int b);
int getlines(char s[]);
void main()
{
	char s[LIMIT];
	while (getlines(s) > 0)
	{
		int arraylen = strlen(s);
		reverse(s, arraylen);
		printf("%s", s);
	}
}
int getlines(char s[])
{
	int c, i;
	for (i = 0; (c = getchar()) != EOF && i < LIMIT - 1; ++i)
	{
		s[i] = c;
		if (c == '\n')
		{
			++i;
			break;
		}
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int arraylen)
{
	int i, j;
	i = 0;
	j = arraylen - 1;
	while (i <= j)
	{
		if (s[j] == '\n')
		{
			--j;
			continue;
		}
		swap(s, i, j);
		i++;
		j--;
	}
}

void swap(char *s, int a, int b)
{
	char temp;
	temp = *(s + a);
	*(s + a) = *(s + b);
	*(s + b) = temp;
}
