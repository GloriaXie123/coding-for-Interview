#include <stdio.h>
int power(int base, int n);
/*implement function power(m,n)*/
main()
{
	int i;
	for (int i = 0; i < 10; ++i)
	{
		printf("%d,%d,%d\n", i, power(2, i), power(-3, i));
	}
	return 0;
}
int power(int base, int n)
{
	int i, p;
	p = 1;

	for (int i = 1; i <= n; ++i)
	{
		p = p * base;
	}
	return p;
}
