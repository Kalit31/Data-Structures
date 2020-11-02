#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: Apply bottom-up dp.
//          For each cell on the topmost row, the robot must have arrived from left. Hence, 1 possible way.
//          Similary, for each cell on the leftmost column, it must have arrived from top. Hence, 1 possible way.
//          For every other cell, we have 2 options. It may come from top or left. Hence, we sum up both the possibilites.

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};