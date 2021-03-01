#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    vector<vector<bool>> vis;

    int build(vector<int> &nums, vector<int> &multipliers, int l, int r, int curr)
    {
        if (l > r)
        {
            return 0;
        }
        if (curr == multipliers.size())
        {
            return 0;
        }
        int n = nums.size();

        if (vis[l][n - 1 - r])
        {
            return dp[l][n - 1 - r];
        }

        int s = 0;

        s = multipliers[curr] * nums[l] + build(nums, multipliers, l + 1, r, curr + 1);
        s = max(s, multipliers[curr] * nums[r] + (build(nums, multipliers, l, r - 1, curr + 1)));
        vis[l][n - 1 - r] = true;
        dp[l][n - 1 - r] = s;

        return s;
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        int score = 0;
        dp.resize(m + 1, vector<int>(m + 1, 0));
        vis.resize(m + 1, vector<bool>(m + 1, false));
        score = build(nums, multipliers, 0, n - 1, 0);

        return score;
    }
};