#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &mat)
    {
        int N = mat.size();
        for (int x = 0; x < N / 2; x++)
        {
            for (int y = x; y < N - x - 1; y++)
            {
                int temp = mat[x][y];
                mat[x][y] = mat[y][N - 1 - x];
                mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
                mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];
                mat[N - 1 - y][x] = temp;
            }
        }
    }

    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        //0 degree
        if (mat == target)
        {
            return true;
        }
        //90 degree
        rotateMatrix(mat);
        if (mat == target)
        {
            return true;
        }
        //180 degree
        rotateMatrix(mat);
        if (mat == target)
        {
            return true;
        }
        //270 degree
        rotateMatrix(mat);
        if (mat == target)
        {
            return true;
        }
        //360 degree
        rotateMatrix(mat);
        if (mat == target)
        {
            return true;
        }
        return false;
    }
};
