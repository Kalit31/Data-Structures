#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> histogram(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++)
        {
            histogram[0][i] = matrix[0][i];

            for (int j = 1; j < m; j++)
                histogram[j][i] = (matrix[j][i] == 0) ? 0 : histogram[j - 1][i] + 1;
        }

        for (int i = 0; i < m; i++)
        {
            sort(histogram[i].begin(), histogram[i].end(), greater<int>());
        }

        int currArea, maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                currArea = (j + 1) * histogram[i][j];
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};