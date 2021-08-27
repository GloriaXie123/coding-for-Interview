#include <stdio.h>

/*write a function setbits that returns x with n bits
that begin at position p set to the rightmost
n bits of y,leaving the other bits unchanged*/

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	/*mark expected position of x to be zero 
	and mark expected position of y to be one.
	*/
	return x & (~(~(~0 >> n) >> p + 1 - n)) | y & (~(~0 >> n) >> p + 1 - n);
}

/*write a function invert(x,p,n) that returns x with the n bits that begin
at position p inverted(i.e., 1 changed to 0 and vice versa),leaving others
unchanged.*/

unsigned int invert(unsigned x, int p, int n)
{
	//firstly get the expected n digits and then keep rest of the digits unchanged

	return ~(x & (~(~0 << n) << p + 1 - n)) | x & (~(~(~0 << n) << p + 1 - n));
}

unsigned int invert(unsigned x, int p, int n)
{
	//firstly get the expected n digits and then keep rest of the digits unchanged

	return x ^ (~(~0 << n) << p + 1 - n);
}

/*write a function rightrot(x,n) that returns the value of 
the integer x rotated to the right by n positions */
//we must consider about word length
unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit;
	while (n-- > 0)
	{
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;
		x = x | rbit;
	}
	return x;
}

int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;

	for (i = 0; v > 0; ++i)
	{
		v = v >> 1;
	}

	return i;
}

unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbits;

	if ((n = n % wordlength()) > 0)
	{
		// get the rightmost n bits
		rbits = ~(~0 << n) & x;
		rbits = x << (wordlength() - n);

		x = x >> n;

		x = x | rbits;
	}
	return x;
}
