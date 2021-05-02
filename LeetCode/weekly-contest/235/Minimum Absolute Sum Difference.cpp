#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        ll orig = 0;
        ll maxDecrement = 0;
        set<int> s(begin(nums1), end(nums1));

        for (int i = 0; i < n; i++)
        {
            ll currDiff = abs(nums1[i] - nums2[i]);
            orig += currDiff;
            auto it = s.lower_bound(nums2[i]);
            if (it != s.begin())
            {
                ll newDiff = abs(*prev(it) - nums2[i]);
                maxDecrement = max(maxDecrement, currDiff - newDiff);
            }
            if (it != s.end())
            {
                ll newDiff = abs(*it - nums2[i]);
                maxDecrement = max(maxDecrement, currDiff - newDiff);
            }
        }

        return (orig - maxDecrement) % mod;
    }
};

//Failed System Testing :'(
// Wrong Idea: Minimize the largest difference
/*
[1,28,21]
[9,21,20]
*/
class Solution
{
public:
    const int mod = 1e9 + 7;
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<array<int, 2>> diff(n);

        for (int i = 0; i < n; i++)
        {
            diff[i] = {abs(nums1[i] - nums2[i]), i};
        }

        sort(diff.begin(), diff.end());

        int maxInd = diff[n - 1][1];
        int newDiff = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            newDiff = min(newDiff, abs(nums1[i] - nums2[maxInd]));
        }

        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = (ans + diff[i][0]) % mod;
        }
        ans = (ans + newDiff) % mod;
        return ans;
    }
};