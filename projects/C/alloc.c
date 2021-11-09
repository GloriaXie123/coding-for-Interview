#include <stdio.h>

#define ALLOCSIZE 10000 /*size of available space*/

static char allocbuf[ALLOCSIZE]; /*storage for allocbuf*/
static char *allocp = allocbuf;	 /*next free position*/

char *alloc(int n) //return pointer after n characters
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return 0;
	}
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
	{
		allocp = p;
	}
}
