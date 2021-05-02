#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        //row-wise prefix sums
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
            }
        }
        int result = 0;

        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = col1; col2 < n; col2++)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int currSum = 0;
                for (int row = 0; row < m; row++)
                {
                    currSum += matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    if (mp.find(currSum - target) != mp.end())
                    {
                        result += mp[currSum - target];
                    }
                    mp[currSum]++;
                }
            }
        }
        return result;
    }
};