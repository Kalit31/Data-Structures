#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxL = 0;
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxL = max(maxL, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        int maxW = 0;
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        }

        const int mod = 1e9 + 7;

        long int ans = ((long int)maxL * (long int)maxW) % mod;
        return ans;
    }
};