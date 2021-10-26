#include <stdio.h>

/*quick sort is the typical recursion example*/
void qsort(int v[], int left, int right)
{
	if (left < right)
	{
		int peak = v[left];
		int i, j;
		j = right + 1;
		for (i = left + 1; i < j; ++i)
		{
			if (v[i] > peak)
			{
				--j;
				swap(v, i, j);
			}
		}
		swap(v, left, j - 1);
		qsort(v, left, j - 2);
		qsort(v, j, right);
	}
	else
	{
		return;
	}
}
