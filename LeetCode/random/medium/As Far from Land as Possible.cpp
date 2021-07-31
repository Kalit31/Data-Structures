#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dirX = {1, 0, -1, 0};
    vector<int> dirY = {0, 1, 0, -1};

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<array<int, 2>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n)
        {
            return -1;
        }
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nxtX = curr[0] + dirX[i];
                int nxtY = curr[1] + dirY[i];
                if (nxtX < 0 || nxtY < 0 || nxtX >= n || nxtY >= n || dist[nxtX][nxtY] != INT_MAX)
                {
                    continue;
                }
                dist[nxtX][nxtY] = 1 + dist[curr[0]][curr[1]];
                q.push({nxtX, nxtY});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dist[i][j]);
            }
        }
        return ans;
    }
};