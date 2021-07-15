#include <stdio.h>

int bitcount(unsigned x);
void main()
{
	unsigned x = 4;
	int nb = bitcount(x);
	printf("the number of 1-bit in x %d is: %d", x, nb);
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			++b;
		}
	}
	return b;
}
