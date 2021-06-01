#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int build(vector<int> &nums1, vector<int> &nums2, int mask, int ind)
    {
        int n = nums1.size();

        if (ind >= n)
        {
            return 0;
        }

        if (dp[mask][ind] != -1)
        {
            return dp[mask][ind];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                ans = min(ans, (nums1[ind] ^ nums2[i]) + build(nums1, nums2, mask | (1 << i), ind + 1));
            }
        }

        return dp[mask][ind] = ans;
    }

    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        dp.resize((1 << n), vector<int>(n, -1));
        return build(nums1, nums2, 0, 0);
    }
};