#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {

        if (matrix.size() == 0)
        {
            return vector<int>();
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int totalCount = m * n;
        vector<int> result(totalCount);
        int curr = 0;
        bool up = true;
        int i = 0, j = 0;
        while (totalCount != 0)
        {
            if (up)
            {
                result[curr] = matrix[i][j];
                curr++;
                totalCount--;
                if (j == n - 1)
                {
                    up = false;
                    i++;
                    continue;
                }
                if (i == 0)
                {
                    up = false;
                    j++;
                }
                else
                {
                    j++;
                    i--;
                }
            }
            else
            {
                result[curr] = matrix[i][j];
                curr++;
                totalCount--;
                if (i == m - 1)
                {
                    up = true;
                    j++;
                    continue;
                }
                if (j == 0)
                {
                    up = true;
                    i++;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return result;
    }
};