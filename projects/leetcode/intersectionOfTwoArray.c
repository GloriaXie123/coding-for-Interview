#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quicksort(int *nums, int low, int high, int numsSize);
void swap(int *nums, int i, int j);
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);

void main()
{
	int nums1 = {1, 2, 2, 1};
	int nums2 = {2, 2};
	int *returnSize;
	int *result;
	int len;
	result = intersect(nums1, 4, nums2, 2, returnSize);

	if (result[0] != NULL)
	{
		int len = sizeof(result) / sizeof(result[0]);
	}

	for (int i = 0; i < len; ++i)
	{
		printf("result[i]");
	}
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{

	quicksort(nums1, 0, nums1Size - 1, nums1Size);
	quicksort(nums2, 0, nums2Size - 1, nums2Size);

	int shorter = nums1Size < nums2Size ? nums1Size : nums2Size;

	for (int i = 0; i < shorter; ++i)
	{
		returnSize[i] = 0;
	}

	int index = 0;

	for (int i = 0; i < nums1Size - 1; ++i)
	{
		for (int j = 0; j < nums2Size; ++j)
		{
			if (*(nums1 + i) == *(nums2 + j))
			{
				returnSize[index] = *(nums1 + i);
				++index;
				break;
			}
		}
	}

	return returnSize;
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
			if (i != j)
			{
				swap(nums, i, j);
			}
		}
	}
	--i;
	swap(nums, i, low);
	quicksort(nums, low, i - 1, numsSize);
	quicksort(nums, i + 1, high, numsSize);
}

void swap(int *nums, int i, int j)
{
	int temp = *(nums + j);
	*(nums + j) = *(nums + i);
	*(nums + i) = temp;
}
