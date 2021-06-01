#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> result;

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
            vector<string> res;
            for (int i = 0; i < n; i++)
            {
                string row = "";
                for (int j = 0; j < n; j++)
                {
                    if (curr[i][j] == 1)
                    {
                        row += 'Q';
                    }
                    else
                    {
                        row += '.';
                    }
                }
                res.push_back(row);
            }
            result.push_back(res);
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

    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        vector<vector<int>> curr(n, vector<int>(n, 0));
        build(curr, 0);
        return result;
    }
};
