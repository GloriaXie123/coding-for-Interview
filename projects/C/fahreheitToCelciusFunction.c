#include <stdio.h>

/*print Fahreheit temperature and its corresponding Celsius temperature by using function to convert
output:
1	-17
2	-6
...
300	148
*/
main()
{
	for (int i = 1; i <= 300; ++i)
	{
		printf("%5.0f\t%5.0f\n", i, celsius(i));
	}
}

float celsius(int fah)
{
	return 5.0 * (fah - 32.0) / 9.0;
}
