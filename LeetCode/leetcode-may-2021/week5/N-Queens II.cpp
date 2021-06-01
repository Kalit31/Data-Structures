#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;

    bool possible(vector<vector<int>> &curr, int row, int col)
    {
        int n = curr.size();
        //a queen should not be already present in the chosen col
        for (int i = 0; i < row; i++)
        {
            if (curr[i][col] == 1)
            {
                return false;
            }
        }
        //a queen should not be already present in the diagonal to the top-left cell
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (curr[i][j] == 1)
            {
                return false;
            }
        }

        //a queen should not be already present in the diagonal to the top-right cell
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (curr[i][j] == 1)
            {
                return false;
            }
        }
        //chosen row and col seems fine
        return true;
    }

    void build(vector<vector<int>> &curr, int currRow)
    {
        int n = curr.size();
        if (currRow == n)
        {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (possible(curr, currRow, col))
            {
                curr[currRow][col] = 1;
                build(curr, currRow + 1);
                curr[currRow][col] = 0;
            }
        }
    }

    int totalNQueens(int n)
    {
        ans = 0;
        vector<vector<int>> curr(n, vector<int>(n, 0));
        build(curr, 0);
        return ans;
    }
};