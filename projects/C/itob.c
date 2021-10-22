#include <stdio.h>

/* write a function itob(n,s,b), that converts integer n into
a base b character representation in the string s. In particular,
itob(n,s,16) formats s as a hexadecimal integer in s. 
*/
#define MAX 36

void itob(int n, char s[], int b);
void reverse(char s[]);

void itob(int n, char s[], int b)
{
	int sign, i;

	sign = n;
	i = 0;

	static char digits[MAX] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (b < 2 || b > 36)
	{
		printf("invalid base: %d", b);
		exit;
	}
	do
	{
		s[i++] = digits[n % b];
	} while (n / b != 0);

	if (sign < 0)
	{
		s[i++] = "-";
	}
	s[i] = '\0';
	reverse(s);
}
