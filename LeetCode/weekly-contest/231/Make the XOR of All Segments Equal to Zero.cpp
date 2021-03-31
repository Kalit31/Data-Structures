#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        vector<vector<int>> cnt(k, vector<int>(1024, 0));

        for (int i = 0; i < nums.size(); i++)
        {
            cnt[i % k][nums[i]]++;
        }

        vector<vector<int>> dp(k + 1, vector<int>(1024, -2000));
        dp[0][0] = 0;

        for (int i = 1; i <= k; i++)
        {
            int maxEle = *max_element(dp[i - 1].begin(), dp[i - 1].end());
            for (int j = 0; j < 1024; j++)
            {
                dp[i][j] = maxEle;
            }
            for (int j = 0; j < 1024; j++)
            {
                if (cnt[i - 1][j] == 0)
                {
                    continue;
                }
                for (int l = 0; l < 1024; l++)
                {
                    dp[i][j ^ l] = max(dp[i][j ^ l], dp[i - 1][l] + cnt[i - 1][j]);
                }
            }
        }
        return nums.size() - dp[k][0];
    }
};