#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> result;
        result.push_back(matrix[0][0]);
        for (int i = 1; i < m; i++)
        {
            matrix[0][i] = matrix[0][i - 1] ^ matrix[0][i];
            result.push_back(matrix[0][i]);
        }
        for (int i = 1; i < n; i++)
        {
            matrix[i][0] = matrix[i - 1][0] ^ matrix[i][0];
            result.push_back(matrix[i][0]);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] = matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1] ^ matrix[i][j];
                result.push_back(matrix[i][j]);
            }
        }

        sort(result.begin(), result.end(), greater<int>());

        return result[k - 1];
    }
};