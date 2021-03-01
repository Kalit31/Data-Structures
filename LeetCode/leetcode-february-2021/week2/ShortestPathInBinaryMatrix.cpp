#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return false;
        }
        else
        {
            if (grid[i][j] == 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return -1;
        }
        int n = grid.size();
        if (grid[0][0] == 1)
        {
            return -1;
        }

        queue<array<int, 2>> q;
        q.push({0, 0});
        int sz = q.size();
        int level = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!q.empty())
        {
            if (sz == 0)
            {
                sz = q.size();
                level++;
            }
            array<int, 2> curr = q.front();
            q.pop();

            if (curr[0] == n - 1 && curr[1] == n - 1)
            {
                return level;
            }

            for (int i = 0; i < 8; i++)
            {
                int nextX = curr[0] + x[i];
                int nextY = curr[1] + y[i];
                if (isValid(grid, nextX, nextY) && !visited[nextX][nextY])
                {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                }
            }
            sz--;
        }
        return -1;
    }
};