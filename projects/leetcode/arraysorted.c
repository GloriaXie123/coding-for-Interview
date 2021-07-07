#include <stdio.h>
#include <stdbool.h>

void quicksort(int *nums, int low, int high, int numsSize);
bool containsDuplicate(int *nums, int numsSize);
void swap(int *nums, int i, int j);

main()
{
	int numsSize = 4;
	int nums[4] = {1, 2, 3, 4};

	containsDuplicate(nums, numsSize);
	for (int i = 0; i < numsSize; ++i)
	{
		printf("%d", *(nums + i));
	}
}

bool containsDuplicate(int *nums, int numsSize)
{
	quicksort(nums, 0, numsSize - 1, numsSize);
	int pre = *(nums);
	if (numsSize > 1)
	{
		for (int i = 0; i < numsSize; ++i)
		{
			int back = *(nums + i + 1);
			if (pre == back)
			{
				return 1;
			}
			else
			{
				pre = back;
			}
		}
	}
	return 0;
}

void quicksort(int *nums, int low, int high, int numsSize)
{
	if (low >= high)
	{
		return;
	}
	int base, i, j;

	i = high + 1;
	printf("initial low: %d,initial high: %d\n", low, high);
	base = *(nums + low);
	printf("base: %d\n", base);

	for (j = high; j > low; --j)
	{
		if (*(nums + j) > base)
		{
			--i;
			swap(nums, i, j);
		}
	}
	--i;
	swap(nums, i, low);
	for (int i = low; i <= high; ++i)
	{
		printf("%d", *(nums + i));
	}
	printf("\n");

	quicksort(nums, low, i - 1, numsSize);
	quicksort(nums, i + 1, high, numsSize);
}

void swap(int *nums, int i, int j)
{
	int temp = *(nums + j);
	printf("pivot:%d\n", temp);
	*(nums + j) = *(nums + i);
	printf("temp:%d\n", *(nums + j));
	*(nums + i) = temp;
}
