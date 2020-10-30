#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        if (n < 1)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (dp[i - j] == 0)
                {
                    dp[i] += dp[j - 1];
                }
                else if (dp[j - 1] == 0)
                {
                    dp[i] += dp[i - j];
                }
                else
                {
                    dp[i] += dp[i - j] * dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};