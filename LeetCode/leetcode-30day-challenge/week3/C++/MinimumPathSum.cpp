#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming

//Approach: Create a dp table and intialize it with zeros.
//          Since all the numbers in the grid are non-negative,
//          the minimum sum path for a row/column would be unique,i.e., straight line from starting pt(0,0)
//          For any other interior cell, a cost would be the current cell cost
//          in addition to minimum of the cost to reach the element above or left to it.
//Complexity: O(M*N) time , O(M*N) space complexity

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int m = grid.size();
        int n = grid[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        // dp[0][0]=grid[0][0];
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i - 1][j - 1];
                }
                else if (j == 1)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[m][n];
    }
};