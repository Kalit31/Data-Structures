#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            //(i-1)th house
            // case 1: do not pick;
            dp[i] = dp[i - 1];
            // case 2:pick
            dp[i] = max(dp[i], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};