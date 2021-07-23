#include <stdio.h>
void moveZeroes(int *nums, int numsSize);

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
	int k, i;
	k = -1;
	for (i = 0; i < numsSize; ++i)
	{
		if (k == -1)
		{
			if (nums[i] == 0)
			{
				k = i;
			}
			continue;
		}
		else if (nums[i] != 0)
		{
			nums[k] = nums[i];
			nums[i] = 0;
			++k;
		}
	}
}
