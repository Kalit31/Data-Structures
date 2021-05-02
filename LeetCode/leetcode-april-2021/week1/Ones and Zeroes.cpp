#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int N = strs.size();
        vector<array<int, 2>> arr(N);
        for (int i = 0; i < N; i++)
        {
            string curr = strs[i];
            int cnt0 = 0;
            int cnt1 = 0;
            for (char ch : curr)
            {
                if (ch == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
            arr[i] = {cnt0, cnt1};
        }
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (arr[i - 1][0] <= j && arr[i - 1][1] <= k)
                    {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - arr[i - 1][0]][k - arr[i - 1][1]]);
                    }
                }
            }
        }
        return dp[N][m][n];
    }
};