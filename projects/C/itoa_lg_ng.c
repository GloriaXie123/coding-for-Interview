#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))
/*modify our itoa version so that it can
print the largest negative number correctly:

in two's complement numeral system, the range of 
number for specific bits is: -2^(n-1) ~ 2^(n-1)-1*/

void itoa(char s[], int n)
{
	int sign, i;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while (n / 10 != 0);

	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);
}
