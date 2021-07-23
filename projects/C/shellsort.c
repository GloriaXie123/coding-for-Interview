#include <stdio.h>
/*sort v[0]...v[n-1] into increasing order*/
void shellsort(int *nums, int numsSize);

void main()
{
	int nums[5] = {3, 2, 1, 12, 18};
	shellsort(nums, 5);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d", nums[i]);
	}
}

void shellsort(int *nums, int numsSize)
{
	int gap, i, j;
	for (gap = numsSize >> 1; gap > 0; gap >>= 1)
	{
		int temp;
		//insert sort
		for (i = gap; i < numsSize; ++i)
		{
			temp = nums[i];
			for (j = i; j >= gap && nums[j - gap] > nums[j]; j -= gap)
			{
				// printf("nums[j]: %d,nums[j-gap]:%d", nums[j], nums[j - gap]);
				nums[j] = nums[j - gap];
			}
			nums[j] = temp;
		}
	}
}
