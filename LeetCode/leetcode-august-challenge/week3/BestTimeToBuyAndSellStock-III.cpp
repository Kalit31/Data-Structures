#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n <= 1)
        {
            return 0;
        }
        else if (n == 2)
        {
            if (prices[0] > prices[1])
            {
                return 0;
            }
            else
            {
                return (prices[1] - prices[0]);
            }
        }

        vector<vector<int>> dp(3, vector<int>(n));
        for (int i = 1; i <= 2; i++)
        {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return (int)dp[2][n - 1];
    }
};