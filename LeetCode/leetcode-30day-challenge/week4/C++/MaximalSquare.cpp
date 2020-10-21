#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: We maintain a dp table, where each cell indicates
//          the max length of square it can be a part of.
//          If the value at any cell is 0, it will surely not be a part of the square we want.
//          So, the value of the dp cell at this pos is 0.
//          If the value is 1, we will have to check that can we form a bigger cell,
//          if we include the 1 at this cell.
//          Finally traverse the table to find the max value.
//          This will be the length of the side of maximal square.
//Complexity: O(N*M) time

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        if (matrix.size() == 0)
        {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        int maxArea = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                maxArea = max(maxArea, dp[i][j]);
            }
        }
        return maxArea * maxArea;
    }
};