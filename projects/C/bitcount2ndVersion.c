#include <stdio.h>
/*in a two's complement number system, x &= (x - 1) deletes the rightmost
1-bit in x, Explain why. Use this observation to write
a faster version of bitcount*/

int bitcount(unsigned x)
{
	int bit = 0;
	while (x > 0)
	{
		++bit;
		x = x & (x - 1);
	}
	return bit;
}
