#include <stdio.h>

/*write the function any(s1,s2), which returns the first location in a string s1,
where any character from string s2 occurs,
or -1 if s1 contains no character from s2.
(the standard library function strpbrk does the same job 
returns a pointer to the location)*/

int any(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				return i;
			}
		}
	}
	return -1;
}
