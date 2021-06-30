#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct compVal
    {
        bool operator()(array<int, 2> const &a, array<int, 2> const &b)
        {
            return a[0] < b[0];
        }
    };

    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = nums[n - 1];
        priority_queue<array<int, 2>, vector<array<int, 2>>, compVal> pq;
        pq.push({dp[n - 1], n - 1});

        for (int i = n - 2; i >= 0; i--)
        {
            while ((pq.top()[1] - i) > k)
            {
                pq.pop();
            }
            dp[i] = nums[i] + pq.top()[0];
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};