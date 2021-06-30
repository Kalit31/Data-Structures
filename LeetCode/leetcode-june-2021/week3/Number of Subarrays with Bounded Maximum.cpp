#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();
        int prev = -1;
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < left)
            {
                dp[i] = (i > 0 ? dp[i - 1] : 0);
            }
            else if (nums[i] > right)
            {
                dp[i] = 0;
                prev = i;
            }
            else
            {
                dp[i] = i - prev;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};