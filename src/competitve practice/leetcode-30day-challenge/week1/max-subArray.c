#include <limits.h>
#include <stdio.h>

int maxSubArray(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    int l = numsSize / 2;
    int left_max = maxSubArray(nums, l);
    int right_max = maxSubArray(nums + l, numsSize - l);
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;

    for (int i = l; i < numsSize; i++)
    {
        sum = sum + nums[i];
        rightSum = sum > rightSum ? sum : rightSum;
    }
    sum = 0;
    for (int i = l - 1; i >= 0; i++)
    {
        sum = sum + nums[i];
        leftSum = sum > leftSum ? sum : leftSum;
    }
    int ans = left_max > right_max ? left_max : right_max;
    int finalAns = ans > (leftSum + rightSum) ? ans : (leftSum + rightSum);
    return finalAns;
}