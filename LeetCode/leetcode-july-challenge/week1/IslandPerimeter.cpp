#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int h = grid.size();
        int w = grid[0].size();

        int per = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == 1)
                {
                    per += 4;
                    if (i > 0 && grid[i - 1][j] == 1)
                    {
                        per -= 2;
                    }

                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        per -= 2;
                    }
                }
            }
        }
        return per;
    }
};