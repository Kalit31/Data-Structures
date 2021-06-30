#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int N = 101;
    int kInversePairs(int n, int k)
    {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
        dp[1][0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if (j >= i)
                {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};
