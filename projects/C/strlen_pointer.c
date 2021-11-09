#include <stdio.h>

/*return the length of string s*/
int strlen(int *s)
{
	int i;
	for (i = 0; *s != '\0'; ++s)
	{
		++i;
	}
	return i;
}

//using pointer arithmetic to calculate string length
int strlen(int *s)
{
	int *p = s;
	while (*p != '\0')
	{
		++p;
	}
	return p - s;
}
