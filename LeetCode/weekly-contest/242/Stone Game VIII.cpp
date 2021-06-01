#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + stones[i];
        }
        int ans = pref[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            ans = max(ans, pref[i] - ans);
        }
        return ans;
    }
};