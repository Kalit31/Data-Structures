#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach: Calculate the slope from the first two points.
//          If the points form a straight line, every consecutive points will yield the same slope
//Complexity: O(N) time

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() == 2)
            return true;
        int xdiff = coordinates[1][0] - coordinates[0][0];
        int ydiff = coordinates[1][1] - coordinates[0][1];

        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            int cxdiff = coordinates[i + 1][0] - coordinates[i][0];
            int cydiff = coordinates[i + 1][1] - coordinates[i][1];
            if (xdiff * cydiff != ydiff * cxdiff)
            {
                return false;
            }
        }
        return true;
    }
};