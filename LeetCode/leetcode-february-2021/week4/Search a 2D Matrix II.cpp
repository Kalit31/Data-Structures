#include <bits/stdc++.h>
using namespace std;

// O(M Lg N) soln
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target)
            {
                if (matrix[i][n - 1] >= target)
                {

                    int l = 0;
                    int r = n - 1;

                    while (l <= r)
                    {
                        int mid = l + (r - l) / 2;
                        if (matrix[i][mid] == target)
                        {
                            return true;
                        }
                        else if (matrix[i][mid] > target)
                        {
                            r = mid - 1;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
        return false;
    }
};

// O(M + N) soln
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};