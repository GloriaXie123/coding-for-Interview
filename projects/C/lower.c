#include <stdio.h>
#include <ctype.h>

/*rewrite a function lower, which convert upper case letters
to lower case letters with a conditional expression
instead of if-else
*/
int lower(int);
void main()
{
	int a = 'Q';
	int result = lower(a);
	putchar(result);
}

int lower(int lowerletter)
{
	return lowerletter >= 'A' && lowerletter <= 'Z' ? lowerletter - 'A' + 'a' : lowerletter;
}
