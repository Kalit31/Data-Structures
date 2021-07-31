#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i == n - 1 || j == m - 1)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    }
                }
            }
        }

        int maxLength = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return maxLength;
    }
};