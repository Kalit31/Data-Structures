#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: We shall use bottom-up dp.
//          For a current value i, the value would be the minimum
//          value of (dp[i-square]+1) for all possible squares less than equal to i.

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

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