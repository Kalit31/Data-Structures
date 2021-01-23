#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int k = 0; k < m; k++)
        {
            vector<int> tmp;
            int i = 0;
            int j = k;
            while (i < n && j < m)
            {
                tmp.push_back(mat[i++][j++]);
            }
            sort(tmp.begin(), tmp.end());
            i = 0;
            j = k;
            int ptr = 0;
            while (i < n && j < m)
            {
                mat[i++][j++] = tmp[ptr++];
            }
        }
        for (int k = 1; k < n; k++)
        {
            vector<int> tmp;
            int i = k;
            int j = 0;
            while (i < n && j < m)
            {
                tmp.push_back(mat[i++][j++]);
            }
            sort(tmp.begin(), tmp.end());
            i = k;
            j = 0;
            int ptr = 0;
            while (i < n && j < m)
            {
                mat[i++][j++] = tmp[ptr++];
            }
        }
        return mat;
    }
};