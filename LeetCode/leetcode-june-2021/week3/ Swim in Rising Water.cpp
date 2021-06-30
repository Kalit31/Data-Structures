#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return false;
        }
        return true;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<int> dirX = {1, 0, -1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        int currTime = 0;
        while (true)
        {
            auto curr = pq.top();
            pq.pop();

            if (visited[curr[1]][curr[2]])
            {
                continue;
            }
            currTime = max(currTime, curr[0]);
            //cout<<"("<<curr[1]<<","<<curr[2]<<"): "<<curr[0]<<endl;
            if (curr[1] == n - 1 && curr[2] == n - 1)
            {
                return currTime;
            }
            visited[curr[1]][curr[2]] = true;

            for (int i = 0; i < 4; i++)
            {
                int nxtX = curr[1] + dirX[i];
                int nxtY = curr[2] + dirY[i];

                if (!isValid(n, nxtX, nxtY))
                {
                    continue;
                }

                pq.push({grid[nxtX][nxtY], nxtX, nxtY});
            }
        }
        return -1;
    }
};