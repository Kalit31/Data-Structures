#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        {
            return false;
        }
        return true;
    }
    vector<int> dirX = {1, 0, -1, 0};
    vector<int> dirY = {0, 1, 0, -1};
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited, int i, int j, bool &poss)
    {
        if (grid1[i][j] == 0)
        {
            poss = false;
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int nxtX = i + dirX[k];
            int nxtY = j + dirY[k];
            if (isValid(grid2, nxtX, nxtY) && !visited[nxtX][nxtY])
            {
                dfs(grid1, grid2, visited, nxtX, nxtY, poss);
            }
        }
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid2[i][j] == 1)
                {
                    bool poss = true;
                    dfs(grid1, grid2, visited, i, j, poss);
                    ans += poss;
                }
            }
        }
        return ans;
    }
};