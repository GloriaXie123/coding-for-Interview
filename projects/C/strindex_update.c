#include <stdio.h>

int strindex(char line[], char pattern[])
{
	int i, j, k, pos;

	i = j = 0;
	pos = -1;
	for (i = 0; line[i] != '\0'; ++i)
	{
		for (k = i; line[k++] == pattern[j++] && pattern[j] != '\0')
			;
		if (j > 0 && pattern[j] == '\0')
		{
			pos = j;
		}
	}
	return pos;
}
