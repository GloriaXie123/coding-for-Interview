#include <stdio.h>

/*
find x in v[0] <= v[1] <= v[2]...<=v[n-1]
*/
int binarysearch(int x, int v[], int n)
{
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (x < v[mid])
		{
			high = mid;
		}
		else if (x > v[mid])
		{
			low = mid;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


