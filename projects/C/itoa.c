#include <stdio.h>
/*converts an number to it's character array:
input:  i = -321
output: {-,3,2,1}*/

itoa(int n, char s[])
{
	int sign, i;
	int i = 0;
	(sign = n) < 0 ? n = -n : n;
	do
	{
		s[i++] = n % 10;
	} while (n /= 10 > 0);
	s[i++] = '\0';
	reverse(s);
}
