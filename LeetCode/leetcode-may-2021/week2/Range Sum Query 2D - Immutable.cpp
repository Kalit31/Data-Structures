#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        //2D prefix sums
        pref.clear();
        pref.resize(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pref[i][j] = matrix[i][j] + (i ? pref[i - 1][j] : 0);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pref[i][j] += (j ? pref[i][j - 1] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = pref[row2][col2];
        ans -= (row1 ? pref[row1 - 1][col2] : 0);
        ans -= (col1 ? pref[row2][col1 - 1] : 0);
        ans += (row1 && col1 ? pref[row1 - 1][col1 - 1] : 0);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */