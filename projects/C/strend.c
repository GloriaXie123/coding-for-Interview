#include <stdio.h>

/*write a function strend(s,t) that returns 1 if string t occurs at the end of
string s, return 0 if not*/
int strend(char *s, char *t)
{
	while (*s == *t || *s != '\0')
	{
		if (*s == *t && *t != '\0')
		{
			if (*t == '\0' && *s == '\0')
			{
				return 1;
			}
			s++;
			t++;
		}
		else
		{
			return 0;
		}
		s++;
	}
	return 0;
}
