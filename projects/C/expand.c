#include <stdio.h>
#define LEN 100
void expand(char[], char[]);
void main()
{
	char s1[LEN] = "a-c";
	char s2[LEN] = "";
	expand(s1, s2);
	printf("%s", s2);
}
// void expand(char s1[], char s2[])
// {
// 	int c;
// 	int i, j;
// 	i = j = 0;
// 	int front, end;
// 	while ((c = s1[i]) != '\0')
// 	{
// 		if (c == '-')
// 		{
// 			if ((i - 1) < 0 || s1[i + 1] == '\0')
// 			{
// 				s2[j] = c;
// 				++j;
// 			}
// 			else
// 			{
// 				front = s1[i - 1];
// 				if ((j - 1) > 0 && front == s2[j - 1])
// 				{
// 					front = s1[i - 1] + 1;
// 				}
// 				end = s1[i + 1];
// 				while (front <= end)
// 				{
// 					s2[j] = front;
// 					++j;
// 					++front;
// 				}
// 			}
// 		}
// 		++i;
// 	}
// 	s2[j] = '\0';
// }

void expand(char s1[], char s2[])
{
	char c;
	int i, j;
	i = j = 0;
	while ((c = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i + 1] >= c)
		{
			++i;
			while (c < s1[i])
			{
				s2[j++] = c++;
			}
		}
		else
		{
			s2[j++] = c;
		}
	}
	s2[j] = '\0';
}
