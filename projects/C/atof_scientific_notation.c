#include <stdio.h>
#define MAX 100
double atof(char[]);
/*extend atof to handle scientific notation*/
void main()
{
	char s[MAX] = "123.34E-2";
	printf("%f", atof(s));
}

double atof(char s[])
{
	int i, k, exponent, sign;
	double sum;
	k = exponent = sign = 0;
	sum = 0.0;

	for (i = 0; s[i] != 'e' && s[i] != 'E'; i++)
	{
		if (s[i] != '.')
		{
			sum = sum * 10 + s[i] - '0';
		}
		else
		{
			k = i;
		}
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		int divisor = i - k - 1;
		while (divisor > 0)
		{
			sum /= 10;
			--divisor;
		}
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = -1;
		}
		else
		{
			exponent = s[i] - '0';
			while (exponent > 0)
			{
				if (sign < 0)
				{
					sum /= 10;
				}
				else
				{
					sum *= 10;
				}
				--exponent;
			}
		}
		i++;
	}
	return sum;
}
