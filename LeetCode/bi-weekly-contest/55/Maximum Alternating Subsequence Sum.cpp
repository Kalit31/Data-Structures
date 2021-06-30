#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(3, 0));

        dp[0] = {0, nums[0], 0};

        for (int i = 1; i < n; i++)
        {
            //do not take nums[i]
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
            //keep nums[i] at odd idx
            dp[i][1] = max(dp[i - 1][1], max((ll)nums[i], nums[i] + dp[i - 1][2]));
            //keep nums[i] at even idx
            dp[i][2] = max(dp[i - 1][2], max((ll)0, dp[i - 1][1] - nums[i]));
            //cout<<dp[i][0]<<" - "<<dp[i][1]<<" - "<<dp[i][2]<<endl;
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};

class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        ll ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            ans += max(0, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};