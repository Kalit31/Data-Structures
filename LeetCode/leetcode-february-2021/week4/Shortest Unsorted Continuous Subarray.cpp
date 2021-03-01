#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int lPtr = 0;
        while (lPtr < n - 1)
        {
            if (nums[lPtr] > nums[lPtr + 1])
            {
                break;
            }
            lPtr++;
        }
        if (lPtr == n - 1)
        {
            return 0;
        }
        int rPtr = n - 1;
        while (rPtr > 1)
        {
            if (nums[rPtr] < nums[rPtr - 1])
            {
                break;
            }
            rPtr--;
        }
        int maxN = INT_MIN;
        int minN = INT_MAX;
        for (int i = lPtr; i <= rPtr; i++)
        {
            maxN = max(maxN, nums[i]);
            minN = min(minN, nums[i]);
        }
        int i = lPtr - 1;
        while (i >= 0)
        {
            if (nums[i] > minN)
            {
                lPtr = i;
            }
            i--;
        }
        i = rPtr + 1;
        while (i < n)
        {
            if (nums[i] < maxN)
            {
                rPtr = i;
            }
            i++;
        }
        return rPtr - lPtr + 1;
    }
};