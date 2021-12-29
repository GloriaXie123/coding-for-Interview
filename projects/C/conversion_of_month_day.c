#include <stdio.h>

static int detab[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// static int *detab[] = {
// 		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
// 		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month < 1 || month > 12 || day < 1 || day > detab[leap][month])
	{
		return -1;
	}
	for (int i = 1; i < month; ++i)
	{
		day += detab[leap][i];
	}
	return day;
}

int day_of_year(int year, int month, int day)
{
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (int i = 1; i < month; ++i)
	{
		day += *(detab[leap] + i);
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > detab[leap][i]; ++i)
	{
		yearday -= detab[leap][i];
	}
	if (i > 12 || yearday < 1 || yearday > detab[leap][i + 1])
	{
		*pmonth = -1;
		*pday = -1;
	}
	*pmonth = i;
	*pday = yearday;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; yearday > *(detab[leap] + i); ++i)
	{
		yearday -= *(detab[leap] + i);
	}
	*pmonth = i;
	*pday = yearday;
}
