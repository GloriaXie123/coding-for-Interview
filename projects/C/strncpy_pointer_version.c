#include <stdio.h>

/*write versions of the library functions strncpy, strncat, and strncmp
which operate on at most the first n characters of their argument strings,
for example, strncpy(s,t,n) copies at most n characters of t to s*/

void strncpy(char *s, char *t, int n)
{
	while (*t && n > 0)
	{
		*s++ = *t++;
		n--;
	}

	while (n > 0)
	{
		*s++ = '\0';
		n--;
	}
}

void strntcat(char *s, char *t, int n)
{
	while (*s++)
		;
	while (*t && n-- > 0)
	{
		*s++ = *t++;
	}
	while (n-- > 0)
	{
		*s++ = '\0';
	}
}

int strncmp(char *s, char *t, int n)
{
	while (n-- > 0)
	{
		if (*s != *t)
		{
			return *s - *t;
		}
		else
		{
			if (*s == '\0' && *t == '\0')
			{
				return 0;
			}
			s++;
			t++;
		}
	}
	return 0;
}

int strncmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
	{
		if (*s == '\0' || n-- <= 0)
		{
			return 0;
		}
	}
	return *s - *t;
}
