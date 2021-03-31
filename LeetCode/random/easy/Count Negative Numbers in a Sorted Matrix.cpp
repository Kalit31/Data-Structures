#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        int cnt = 0;

        while (j >= 0)
        {
            while (i < m && grid[i][j] >= 0)
            {
                i++;
            }
            cnt += m - i;
            j--;
        }

        return cnt;
    }
};