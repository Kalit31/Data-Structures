#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        int maxLen = 0;
        vector<int> size(n);
        for (int i = 0; i < n; i++)
        {
            size[i] = min(rectangles[i][0], rectangles[i][1]);
            maxLen = max(maxLen, size[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (size[i] == maxLen)
                cnt++;
        }
        return cnt;
    }
};