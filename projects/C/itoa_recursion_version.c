#include <stdio.h>
#define MAXVAL 10;

/*convert number to string by using recursion*/
void itoa(int);
main()
{
	static int i, n;

	i = 0;
	n = 123;
	char s[MAXVAL];

	atof(n);

	s[i] = '0';
	printf("print integer n: %s", s);
}

void itoa(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		printd(n / 10);
	}
	if (i < MAXVAL - 1)
	{
		s[i] = n % 10 + '0';
		++i; //put char `1`,`2`,`3`....
	}
}
