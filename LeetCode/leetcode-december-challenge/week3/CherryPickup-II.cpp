#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int build(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int col1, int col2)
    {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
        {
            return 0;
        }
        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }

        int cherriesPicked = 0;

        cherriesPicked = grid[row][col1];

        if (col1 != col2)
        {
            cherriesPicked += grid[row][col2];
        }

        if (row != grid.size() - 1)
        {
            // max of 9 moves
            int maxCherries = 0;
            for (int i = col1 - 1; i <= col1 + 1; i++)
            {
                for (int j = col2 - 1; j <= col2 + 1; j++)
                {
                    maxCherries = max(maxCherries, build(grid, dp, row + 1, i, j));
                }
            }
            cherriesPicked += maxCherries;
        }

        dp[row][col1][col2] = cherriesPicked;
        return cherriesPicked;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return build(grid, dp, 0, 0, m - 1);
    }
};