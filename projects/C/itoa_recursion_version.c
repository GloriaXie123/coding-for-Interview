#include <stdio.h>

/*convert number to string by using recursion*/

void printd(int n)
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
	putchar(n % 10 + '0'); //put char `1`,`2`,`3`....
}
