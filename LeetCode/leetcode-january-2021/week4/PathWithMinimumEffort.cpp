#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dX = {1, 0, -1, 0};
    vector<int> dY = {0, 1, 0, -1};

    bool inBounds(int n, int m, int x, int y)
    {
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool poss(vector<vector<int>> &heights, int maxDiff)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<array<int, 2>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            array<int, 2> curr = q.front();
            q.pop();
            if (curr[0] == (n - 1) && curr[1] == (m - 1))
            {
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int nextX = curr[0] + dX[i];
                int nextY = curr[1] + dY[i];
                if (!inBounds(n, m, nextX, nextY))
                {
                    continue;
                }
                if (!visited[nextX][nextY])
                {
                    if (abs(heights[nextX][nextY] - heights[curr[0]][curr[1]]) <= maxDiff)
                    {
                        q.push({nextX, nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        int low = 0;
        int high = 1e6;
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (poss(heights, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};