#include <stdio.h>

/*concatenate string s to t, s must be 
big enough*/

void strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s = *t)
	{
		s++;
		t++;
	}
}
