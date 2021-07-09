#include <stdio.h>
#include <stdbool.h>

bool quicksort(int *nums, int low, int high, int numsSize);
bool containsDuplicate(int *nums, int numsSize);
void swap(int *nums, int i, int j);

void main()
{
	int numsSize = 4;
	int nums[4] = {1, 2, 3, 1};

	quicksort(nums, 0, numsSize - 1, numsSize);
	// containsDuplicate(nums, numsSize);
	for (int i = 0; i < numsSize; ++i)
	{
		printf("%d", *(nums + i));
	}
}

bool quicksort(int *nums, int low, int high, int numsSize);
void swap(int *nums, int i, int j);

bool containsDuplicate(int *nums, int numsSize)
{
	return quicksort(nums, 0, numsSize - 1, numsSize);
}

bool quicksort(int *nums, int low, int high, int numsSize)
{
	if (low >= high)
	{
		return 0;
	}
	int base, i, j;

	i = high + 1;
	base = *(nums + low);

	for (j = high; j > low; --j)
	{
		if (*(nums + j) == base)
		{
			return 1;
		}

		if (*(nums + j) > base)
		{
			--i;
			if (j != i)
			{
				swap(nums, i, j);
			}
		}
	}
	--i;
	swap(nums, i, low);

	return quicksort(nums, low, i - 1, numsSize) || quicksort(nums, i + 1, high, numsSize);
}

void swap(int *nums, int i, int j)
{
	int temp = *(nums + j);
	*(nums + j) = *(nums + i);
	*(nums + i) = temp;
}
