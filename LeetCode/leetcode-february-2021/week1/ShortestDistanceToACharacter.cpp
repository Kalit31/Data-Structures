#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        int n = s.size();
        vector<int> ans(n, INT_MAX);
        int lastPos = -n;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                lastPos = i;
            }
            ans[i] = i - lastPos;
        }

        lastPos = 2 * n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                lastPos = i;
            }
            ans[i] = min(ans[i], lastPos - i);
        }

        return ans;
    }
};