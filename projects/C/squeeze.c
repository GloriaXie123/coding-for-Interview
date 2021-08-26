#include <stdio.h>
#include <string.h>
#define NEGATIVE -1
/*write an alternative version of squeeze(s1,s2), 
that deletes each character in s1
that matches any character in the string s2*/
void squeeze(char[], char[]);
void squeeze_zero(char[]);
void main()
{
	char s1[] = "abdcc";
	char s2[] = "aad";
	squeeze(s1, s2);
	printf("After squeezing:%s\n", s1);
}
void squeeze(char s1[], char s2[])
{
	for (int j = 0; s2[j] != '\0'; j++)
	{
		int pos = 0;
		for (int i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[j])
			{
				s1[pos++] = s1[i];
			}
		}
		s1[pos] = '\0';
	}
}
