#include <stdio.h>

/*write a function htoi(s),which converts a string of hexadecimal digits(including an optional 0x or 0X) into its equivalent integer value.
the allowable digits are 0 through 9,a through f and A through F*/
#define LIMIT 10000
#define hexbase 16
#define YES 1
#define NO 0
int htoi(char s[]);
int powerf(int base, int i);
main()
{
	int c, i;
	char s[LIMIT];
	for (i = 0; (c = getchar()) != EOF; ++i)
	{
		s[i] = c;
	}
	printf("corresponding decimal is: %d\n", htoi(s));
	s[i] = '\0';
	printf("original input is: %s\n", s);
}

int htoi(char s[])
{
	int inhex, hexdigit, n, power;
	int i = 0;
	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'X' || s[i] == 'x')
		{
			++i;
		}
	}

	n = 0;
	int num = i;
	for (; inhex == YES; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			hexdigit = s[i] - '0';
		}
		else if (s[i] >= 'a' && s[i] <= 'f')
		{
			hexdigit = s[i] - 'a' + 10;
		}
		else if (s[i] >= 'A' && s[i] <= 'F')
		{
			hexdigit = s[i] - 'A' + 10;
		}
		else
		{
			inhex == NO;
		}
		n = n + hexdigit * powerf(hexbase, i - num);
	}
	return n;
}

int powerf(int base, int i)
{
	int p = 1;
	while (i > 0)
	{
		p = p * base;
		--i;
	}
	return p;
}
