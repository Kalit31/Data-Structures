#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result;

        set<int> dist;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int side = 0; side < n; side++)
                {
                    if (i + side < n && i - side >= 0 && j + 2 * side < m)
                    {
                        int curr = 0;
                        int x = i;
                        int y = j;
                        while (x >= (i - side))
                        {
                            curr += grid[x--][y++];
                        }
                        if (side > 0)
                        {
                            x += 2;
                            while (x <= i)
                            {
                                curr += grid[x++][y++];
                            }
                            y -= 2;
                            while (x <= (i + side))
                            {
                                curr += grid[x++][y--];
                            }
                            x -= 2;
                            while (x > i)
                            {
                                curr += grid[x--][y--];
                            }
                        }
                        dist.insert(curr);
                        if (dist.size() > 3)
                        {
                            dist.erase(dist.begin());
                        }
                    }
                }
            }
        }

        for (int x : dist)
        {
            result.push_back(x);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};