#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int build(vector<int> &stones, vector<int> &pref, vector<vector<bool>> &visited, vector<vector<int>> &dp, int l, int r, int turn)
    {
        int n = stones.size();
        if (l >= r)
        {
            return 0;
        }
        if (visited[l][r])
        {
            return dp[l][r];
        }
        int ans;
        if (turn == 0)
        {
            //alice's turn
            //alice would try to maximise the ans
            int way1 = build(stones, pref, visited, dp, l + 1, r, 1 - turn) + (pref[r] - pref[l]);
            int way2 = build(stones, pref, visited, dp, l, r - 1, 1 - turn) + (pref[r - 1] - (l > 0 ? pref[l - 1] : 0));
            ans = max(way1, way2);
        }
        else
        {
            //bob's turn
            //bob would try to minimise the ans
            int way1 = build(stones, pref, visited, dp, l + 1, r, 1 - turn) - (pref[r] - pref[l]);
            int way2 = build(stones, pref, visited, dp, l, r - 1, 1 - turn) - (pref[r - 1] - (l > 0 ? pref[l - 1] : 0));
            ans = min(way1, way2);
        }
        visited[l][r] = true;
        return dp[l][r] = ans;
    }

    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + stones[i];
        }
        vector<vector<bool>> visited(n, vector<bool>(n));
        //no need of 'turn' as a 3rd dimension to dp table
        //as 'l' and 'r' would be able to define the turn variable
        vector<vector<int>> dp(n, vector<int>(n));
        return build(stones, pref, visited, dp, 0, n - 1, 0);
    }
};