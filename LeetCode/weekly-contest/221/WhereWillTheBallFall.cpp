#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for (int k = 0; k < n; k++)
        {
            int i = 0;
            int j = k;
            while (i < m)
            {
                //cout<<"("<<i<<","<<j<<")"<<endl;
                if (grid[i][j] == 1)
                {
                    if (j == (n - 1) || grid[i][j + 1] == -1)
                    {
                        ans[k] = -1;
                        break;
                    }
                    else
                    {
                        i++;
                        j++;
                    }
                }
                else
                {
                    if (j == 0 || grid[i][j - 1] == 1)
                    {
                        ans[k] = -1;
                        break;
                    }
                    else
                    {
                        i++;
                        j--;
                    }
                }
            }
            if (i == m)
                ans[k] = j;
        }
        return ans;
    }
};