#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic programming
//Approach: Knapsack type problem
//Complexity: O(NUM_COINS*AMT) time and space

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= coins.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                // Do not take ith coin
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0)
                {
                    // take ith coin. remaining sum = j-coins[i-1];
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        int n = amount;
        int m = coins.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = coins[i]; j <= n; j++)
                dp[j] = (dp[j] + dp[j - coins[i]]);

        return dp[n];
    }
};