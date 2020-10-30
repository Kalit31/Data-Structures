#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxSubsetSize = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    if (maxSubsetSize < dp[i])
                    {
                        maxSubsetSize = dp[i];
                    }
                }
            }
        }
        vector<int> result;
        int lastPicked = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dp[i] == maxSubsetSize && (lastPicked == -1 || lastPicked % nums[i] == 0))
            {
                result.push_back(nums[i]);
                maxSubsetSize--;
                lastPicked = nums[i];
            }
        }
        return result;
    }
};