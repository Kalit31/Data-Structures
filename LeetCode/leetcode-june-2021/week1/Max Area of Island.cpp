#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int currArea = 0;
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        {
            return;
        }
        currArea++;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    currArea = 0;
                    dfs(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};