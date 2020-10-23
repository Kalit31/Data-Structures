#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: Upon observing the problem closely,
//           one can find it is a variation of longest common sequence problem
//Complexity: O(N*M) time and O(N*M) space

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size(), dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        return dp[m][n];
    }
};

class Solution
{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B)
    {
        int m = A.size();
        int n = B.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};