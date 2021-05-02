#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> moveX = {1, 0, -1, 0};
    vector<int> moveY = {0, 1, 0, -1};
    int m, n;
    bool movePossible(int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }

    int dfs(vector<vector<int>> &matrix, int currX, int currY, vector<vector<int>> &dp)
    {
        if (dp[currX][currY] != -1)
        {
            return dp[currX][currY];
        }

        int ways = 1;

        for (int i = 0; i < 4; i++)
        {
            int nextX = currX + moveX[i];
            int nextY = currY + moveY[i];
            if (!movePossible(nextX, nextY))
                continue;
            if (matrix[nextX][nextY] > matrix[currX][currY])
            {
                ways = max(ways, 1 + dfs(matrix, nextX, nextY, dp));
            }
        }
        return dp[currX][currY] = ways;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == -1)
                {
                    dfs(matrix, i, j, dp);
                }
            }
        }
        int maxPath = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxPath = max(maxPath, dp[i][j]);
            }
        }
        return maxPath;
    }
};