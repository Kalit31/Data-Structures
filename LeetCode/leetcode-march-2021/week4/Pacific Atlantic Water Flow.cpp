#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> moveX = {1, 0, -1, 0};
    vector<int> moveY = {0, -1, 0, 1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> result;
        if (matrix.size() == 0)
        {
            return result;
        }
        int m = matrix.size();
        int n = matrix[0].size();

        queue<array<int, 2>> qPac;
        queue<array<int, 2>> qAtl;

        for (int i = 0; i < m; i++)
        {
            qPac.push({i, 0});
            qAtl.push({i, n - 1});
        }

        for (int j = 0; j < n; j++)
        {
            qPac.push({0, j});
            qAtl.push({m - 1, j});
        }

        vector<vector<bool>> visPac(m, vector<bool>(n, false));
        vector<vector<bool>> visAtl(m, vector<bool>(n, false));

        while (!qPac.empty())
        {
            array<int, 2> curr = qPac.front();
            qPac.pop();
            visPac[curr[0]][curr[1]] = true;

            for (int i = 0; i < 4; i++)
            {
                int nextX = curr[0] + moveX[i];
                int nextY = curr[1] + moveY[i];

                if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)
                {
                    continue;
                }
                if (visPac[nextX][nextY])
                {
                    continue;
                }
                if (matrix[curr[0]][curr[1]] > matrix[nextX][nextY])
                {
                    continue;
                }
                qPac.push({nextX, nextY});
            }
        }

        while (!qAtl.empty())
        {
            array<int, 2> curr = qAtl.front();
            qAtl.pop();
            visAtl[curr[0]][curr[1]] = true;

            for (int i = 0; i < 4; i++)
            {
                int nextX = curr[0] + moveX[i];
                int nextY = curr[1] + moveY[i];

                if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n)
                {
                    continue;
                }
                if (visAtl[nextX][nextY])
                {
                    continue;
                }
                if (matrix[curr[0]][curr[1]] > matrix[nextX][nextY])
                {
                    continue;
                }
                qAtl.push({nextX, nextY});
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visPac[i][j] && visAtl[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};