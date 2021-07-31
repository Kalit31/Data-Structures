#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        const int mod = 1e9 + 7;
        vector<vector<ll>> dp(n + 1, vector<ll>(5, 0));
        // a - e - i - o - u
        dp[1] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % mod;
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][4] = (dp[i - 1][0]);
        }
        ll ans = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]) % mod;
        return ans;
    }
};