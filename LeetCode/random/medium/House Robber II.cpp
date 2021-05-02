#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob1(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            //(i-1)th house
            // case 1: do not pick;
            dp[i] = dp[i - 1];
            // case 2:pick
            dp[i] = max(dp[i], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }
        else if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        else if (n == 3)
        {
            return max(nums[0], max(nums[1], nums[2]));
        }

        vector<int> nums1;
        for (int i = 0; i < (n - 1); i++)
        {
            nums1.push_back(nums[i]);
        }
        int ans1 = rob1(nums1);

        vector<int> nums2;
        for (int i = 1; i < (n); i++)
        {
            nums2.push_back(nums[i]);
        }
        int ans2 = rob1(nums2);

        return max(ans1, ans2);
    }
};