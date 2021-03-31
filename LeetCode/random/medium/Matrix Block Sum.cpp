#include <bits/stdc++.h>
using namespace std;

// O(M*N)
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        //2D prefix sums
        vector<vector<int>> pref(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pref[i][j] = mat[i][j] + (i ? pref[i - 1][j] : 0);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pref[i][j] += (j ? pref[i][j - 1] : 0);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int iLow = max(0, i - K);
                int iHigh = min(m - 1, i + K);
                int jLow = max(0, j - K);
                int jHigh = min(n - 1, j + K);
                ans[i][j] = pref[iHigh][jHigh] - (iLow ? pref[iLow - 1][jHigh] : 0) - (jLow ? pref[iHigh][jLow - 1] : 0) + (iLow && jLow ? pref[iLow - 1][jLow - 1] : 0);
            }
        }

        return ans;
    }
};

// O(M*N*min(M,N))
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        vector<vector<int>> pref(m, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pref[i][j] = pref[i][j - 1] + mat[i][j - 1];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int iLow = max(0, i - K);
                int iHigh = min(m - 1, i + K);
                int jLow = max(0, j - K);
                int jHigh = min(n - 1, j + K);
                for (int k = iLow; k <= iHigh; k++)
                {
                    ans[i][j] += pref[k][jHigh + 1] - pref[k][jLow];
                }
            }
        }
        return ans;
    }
};