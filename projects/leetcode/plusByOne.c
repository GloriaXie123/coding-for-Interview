/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
int power(int i, int j);
int *plusOne(int *digits, int digitsSize, int *returnSize);

void main()
{
	int input[] = {1, 2, 3};
	int returnSize = 0;
	int *result = plusOne(input, 3, &returnSize);
	printf("%d\n", returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d, ", result[i]);
	}
	printf("\n");
}
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int n = 0;
	int j = 0;
	int base = 10;
	for (int i = digitsSize - 1; i >= 0; --i)
	{
		n = n + digits[i] * power(base, j);
		++j;
	}

	int fullnum = 0;
	for (int i = 0; i < digitsSize; ++i)
	{
		fullnum = fullnum + power(base, i);
	}
	fullnum *= 9;
	if (n != fullnum)
	{
		*returnSize = digitsSize;
	}
	else
	{
		*returnSize = digitsSize + 1;
	}
	int *ret = (int *)malloc(*returnSize * sizeof(int));
	for (int i = 0; i < *returnSize; ++i)
	{
		ret[i] = 0;
	}

	printf("[plusOne]: before plusing, %d\n", n);
	++n;
	printf("[plusOne]: after plusing, %d\n", n);
	int end = *returnSize - 1;
	while (n != 0 && end >= 0)
	{
		ret[end] = n % base;
		n -= ret[end];
		n /= base;
		end--;
	}
	return ret;
}

int power(int base, int j)
{
	int p = 1;
	while (j > 0)
	{
		p *= base;
		--j;
	}
	return p;
}
