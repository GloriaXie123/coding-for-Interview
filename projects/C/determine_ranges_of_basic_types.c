#include <stdio.h>
#include <limits.h>
#include <float.h>
/*write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers and by
direct computation.
Harder if you compute them: determine the ranges of the various floating-point types*/

void main()
{
	printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of unsigned char 0 to %d\n", UCHAR_MAX);

	printf("Range of signed short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int: 0 to %d\n", USHRT_MAX);

	printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);
	printf("Range of unsigned int 0 to %u \n", UINT_MAX);

	printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long int 0 to %lu \n", ULONG_MAX);

	printf("Range of signed long long int %lld to %lld\n", LLONG_MIN, LLONG_MAX);
	printf("Range of unsigned long long int %llu\n", ULLONG_MAX);

	printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
	printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
	printf("Range of long double %Lf to %Lf\n", LDBL_MIN, LDBL_MAX);
}
