#include <stdio.h>
void escape(char[], char[]);
#define LEN 100

void main()
{
	char s[LEN] = "abcd\n\t";
	char t[LEN] = "";
	escape(s, t);
	printf("%s", t);
}

void escape(char s[], char t[])
{
	int c;
	int i, j;
	for (i = j = 0; (c = s[i]) != '\0'; ++i)
	{
		switch (c)
		{
		case '\n':
			t[j] = '\\';
			++j;
			t[j] = 'n';
			break;
		case '\t':
			t[j] = '\\';
			++j;
			t[j] = 't';
			break;
		default:
			t[j] = c;
			break;
		}
		++j;
	}
	t[j] = '\0';
}
