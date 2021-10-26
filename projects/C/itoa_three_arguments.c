#include <stdio.h>
#define WIDTH 10
#define abs(x) ((x) < 0 ? -(x) : (x))
/*write a version of itoa that accepts three arguments instead of 
two,the third argument is minimum field width;the converted number
must be padded with blanks on the left with blanks if necessary
to make it wide enough*/
void reverse(char[]);

void itoa(int n, char s[], int width)
{
	int sign, i;

	sign = n;
	i = 0;
	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n / 10) != 0);

	if (sign < 0)
	{
		s[i++] = '-';
	}
	while (i < width)
	{
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}
