#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int build(vector<int> &nums, int target, vector<int> &dp)
    {
        if (dp[target] != -1)
        {
            return dp[target];
        }
        int ways = 0;
        for (int x : nums)
        {
            if (x <= target)
            {
                ways += build(nums, target - x, dp);
            }
        }
        return dp[target] = ways;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return build(nums, target, dp);
    }
};