#include <stdio.h>
void moveZeroes(int *nums, int numsSize);
void swap(int *nums, int i, int j);

main()
{
	int nums[] = {0, 1, 0, 3, 12};
	moveZeroes(nums, 5);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d", nums[i]);
	}
}

void moveZeroes(int *nums, int numsSize)
{
	int k, i, j;
	k = -1;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] != 0)
		{
			j = i;
			while (j > k + 1)
			{
				swap(nums, j, j - 1);
				--j;
			}
			++k;
		}
	}
}

void swap(int *nums, int i, int j)
{
	int temp = *(nums + i);
	*(nums + i) = *(nums + j);
	*(nums + j) = temp;
}
