#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string result = "";
        int i = n;
        int j = m;

        while (i > 0 && j > 0)
        {
            if (dp[i][j] == dp[i - 1][j])
            {
                result = str1[i - 1] + result;
                i--;
            }
            else if (dp[i][j] == dp[i][j - 1])
            {
                result = str2[j - 1] + result;
                j--;
            }
            else if (dp[i][j] == 1 + dp[i - 1][j - 1])
            {
                result = str1[i - 1] + result;
                i--;
                j--;
            }
        }
        while (i != 0)
        {
            result = str1[i - 1] + result;
            i--;
        }

        while (j != 0)
        {
            result = str2[j - 1] + result;
            j--;
        }
        return result;
    }
};