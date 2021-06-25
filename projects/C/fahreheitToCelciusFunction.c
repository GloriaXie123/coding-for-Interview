#include <stdio.h>

float toCelsius(int fah);

/*print Fahreheit temperature and its corresponding Celsius temperature by using function to convert
output:
1	-17
2	-6
...
300	148
*/
void main()
{
	for (int i = 1; i <= 300; ++i)
	{
		printf("%5d\t%5.0f\n", i, toCelsius(i));
	}
}

float toCelsius(int fah)
{
	return 5.0 * (fah - 32.0) / 9.0;
}
