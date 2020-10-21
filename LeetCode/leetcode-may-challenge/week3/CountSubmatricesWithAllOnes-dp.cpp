#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: Create a dp table and intitialise its first row and first col
//          Now, iteratively traverse the dp table,
//          if at a cell(i,j) is 1, we will have to check is it possible to form a bigger square
//          If yes, account for it in the totalCount.
//Complexity: O(N*M) time and O(N*M) space

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};