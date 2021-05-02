#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        vector<int> arr(triangle[n - 1].size(), 0);

        for (int i = 0; i < triangle[n - 1].size(); i++)
        {
            arr[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> tArr(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++)
            {
                tArr[j] = triangle[i][j] + min(arr[j], arr[j + 1]);
            }
            for (int j = 0; j < tArr.size(); j++)
            {
                arr[j] = tArr[j];
            }
        }
        return arr[0];
    }
};