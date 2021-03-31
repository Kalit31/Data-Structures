#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int minDist = INT_MAX;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            if (points[i][0] == x || points[i][1] == y)
                minDist = min(minDist, abs(x - points[i][0]) + abs(y - points[i][1]));
        }
        if (minDist == INT_MAX)
        {
            return -1;
        }
        bool poss = false;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (points[i][0] == x || points[i][1] == y)
            {
                int dist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dist == minDist)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};