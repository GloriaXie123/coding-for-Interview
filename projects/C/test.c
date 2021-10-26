#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVAL 1000
void main()
{
	int s[MAXVAL];
	// int a = 100, b = 200;
	// a = b = 300;
	// printf("%d,%d\n", a, b);
	// int c;
	// char s[MAXVAL];
	// while ((s[0] = c = getchar()) == ' ' || c == '\t'o)
	// 	printf("c is : %d, s[0] is: %d", c, s[0]);
	// ;
	int i = 0;
	int c = '1';
	// s[++i] = 'a';
	// s[i] = '\0';
	// printf("%d\n", i);
	// printf("%d\n", s[0]);
	s[0] = '1';
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = 'a'))
			;
	}
	printf("i is :%d,s[i] is: %d,s[0] is %d", i, s[i], s[0]);
}
