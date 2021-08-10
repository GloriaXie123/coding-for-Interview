#include <stdio.h>
#include <ctype.h>

/*convert string s to double*/
double atof(char s[])
{
	int i, sign;
	double val, power;
	for (i = 0; isspace(s[i]); ++i)
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '-' || s[i] == '+')
	{
		++i;
	}

	for (val = 0.0; isdigit(s[i]); ++i)
	{
		val = val * 10.0 + s[i] - '0';
	}

	if (s[i] == '.')
	{
		++i;
	}
	for (power = 1.0; isdigit(s[i]); ++i)
	{
		val = val * 10.0 + s[i] - '0';
		power = power * 10;
	}
	val = sign * val / power;
	return val;
}
