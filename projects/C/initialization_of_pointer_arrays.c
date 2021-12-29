#include <stdio.h>
char *month_name(int n);
void main()
{
	// char *p;
	// p = month_name(6);
	printf("%s\n", month_name(6));
}

char *month_name(int n)
{
	static char *name[] = {"Iilegal month name",
												 "January",
												 "Feburary",
												 "March",
												 "April",
												 "May",
												 "June",
												 "July",
												 "August",
												 "Sepetember",
												 "October",
												 "Novermber",
												 "December"};
	return (n < 1 || n > 12) ? name[0] : name[n];
}
