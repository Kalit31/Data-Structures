#include <bits/stdc++.h>
using namespace std;

//Type: Depth First Search
//Approach: Start with the standard DFS, and change color of each cell accordingly
//Complexity:  O(N*M) time

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        if (image[sr][sc] == newColor)
        {
            return image;
        }

        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int origColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != origColor)
        {
            return;
        }

        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, origColor);
        dfs(image, sr, sc + 1, newColor, origColor);
        dfs(image, sr - 1, sc, newColor, origColor);
        dfs(image, sr, sc - 1, newColor, origColor);
    }
};