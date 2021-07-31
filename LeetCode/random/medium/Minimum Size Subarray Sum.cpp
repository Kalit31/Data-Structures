#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int len = INT_MAX;

        int i = 0;
        int currSum = 0;
        for (int j = 0; j < n; j++)
        {
            currSum += nums[j];
            while (currSum - nums[i] >= target)
            {
                currSum -= nums[i];
                i++;
            }
            if (currSum >= target)
            {
                len = min(len, j - i + 1);
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};