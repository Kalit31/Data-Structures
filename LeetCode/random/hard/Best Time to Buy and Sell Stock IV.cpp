#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }
        k = min(k, n);
        vector<vector<int>> dp(k + 1, vector<int>(n));

        for (int i = 1; i <= k; i++)
        {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};