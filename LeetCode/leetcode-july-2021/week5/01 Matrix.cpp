#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> dirX = {1, 0, -1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<array<int, 2>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nxtX = curr[0] + dirX[i];
                int nxtY = curr[1] + dirY[i];

                if (nxtX < 0 || nxtY < 0 || nxtX >= m || nxtY >= n || dist[nxtX][nxtY] != -1)
                {
                    continue;
                }

                dist[nxtX][nxtY] = 1 + dist[curr[0]][curr[1]];
                q.push({nxtX, nxtY});
            }
        }
        return dist;
    }
};