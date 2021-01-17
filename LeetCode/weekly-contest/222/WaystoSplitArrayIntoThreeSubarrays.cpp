#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long int
    const int mod = 1e9 + 7;

    int helper(vector<int> &pref, int idx, bool leftmost)
    {
        int n = pref.size();
        int l = idx;
        int r = n - 2;
        int lSum = pref[idx - 1];
        int res = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int mSum = pref[mid] - pref[idx - 1];
            int rSum = pref[n - 1] - pref[mid];

            if (lSum <= mSum && mSum <= rSum)
            {
                res = mid;
                if (leftmost)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (lSum > mSum)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }

    int waysToSplit(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }

        ll ways = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int left = helper(pref, i, true);
            int right = helper(pref, i, false);

            if (left == -1 || right == -1)
            {
                continue;
            }
            ways = (ways + (right - left + 1)) % mod;
        }

        return ways;
    }
};