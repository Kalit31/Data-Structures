#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cnt = 0;

    bool isValid(vector<vector<int>> &grid, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == -1)
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<int>> &grid, int currX, int currY, vector<vector<bool>> &visited)
    {
        if (!isValid(grid, currX, currY) || visited[currX][currY])
        {
            return;
        }
        visited[currX][currY] = true;
        if (grid[currX][currY] == 2)
        {
            for (int i = 0; i < visited.size(); i++)
            {
                for (int j = 0; j < visited[0].size(); j++)
                {
                    if (grid[i][j] != -1 && !visited[i][j])
                    {
                        visited[currX][currY] = false;
                        return;
                    }
                }
            }
            cnt++;
            visited[currX][currY] = false;
            return;
        }
        dfs(grid, currX + 1, currY, visited);
        dfs(grid, currX - 1, currY, visited);
        dfs(grid, currX, currY + 1, visited);
        dfs(grid, currX, currY - 1, visited);
        visited[currX][currY] = false;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, visited);
                    break;
                }
            }
        }
        return cnt;
    }
};