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
	int ret[numsSize];
	int front = 0;
	int end = numsSize - 1;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == 0)
		{
			ret[end] = nums[i];
			--end;
		}
		else if (nums[i] != 0)
		{
			ret[front] = nums[i];
			++front;
		}
	}
	int i = 0;
	while (i < numsSize)
	{
		nums[i] = ret[i];
		++i;
	}
}
