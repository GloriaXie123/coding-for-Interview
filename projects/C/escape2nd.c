#include <stdio.h>
#define LEN 100
void escape(char s[], char t[]);
void main()
{
	char s[LEN] = "asd\t\t";
	char t[LEN] = "";
	escape(s, t);
	printf("%s", t);
}

void escape(char s[], char t[])
{
	int c, tmp;
	int i, j;

	for (i = j = 0; (c = s[i]) != '\0'; ++i)
	{
		switch (c)
		{
		case '\\':
			++i;
			tmp = s[i];
			switch (tmp)
			{
			case 'n':
				t[j] = '\n';
				break;
			case 't':
				t[j] = '\t';
				break;
			default:
				t[j] = '\\';
				break;
			}
		default:
			t[j] = c;
			break;
		}
		++j;
	}
	t[j] = '\0';
}
