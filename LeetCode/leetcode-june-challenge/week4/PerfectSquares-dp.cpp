#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = -1;
        }
        if (n == 2)
        {
            dp[2] = 2;
        }
        if (n == 3)
        {
            dp[2] = 2;
            dp[3] = 3;
        }
        return minSquares(n, dp);
    }

    int minSquares(int n, int dp[])
    {
        if (dp[n] == -1)
        {
            int minS = INT_MAX;
            for (int i = 1; i * i <= n; i++)
            {
                if (n - (i * i) >= 0)
                {
                    minS = min(minSquares(n - (i * i), dp) + 1, minS);
                }
            }
            dp[n] = minS;
        }
        return dp[n];
    }
};