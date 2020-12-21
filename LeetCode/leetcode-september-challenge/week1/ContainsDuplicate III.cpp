#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n = nums.size();
        if (t == 0)
        {
            set<int> s(nums.begin(), nums.end());
            if (s.size() == nums.size())
                return false;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n && (j <= i + k); j++)
            {
                long long int diff = abs((long long int)nums[i] - (long long int)nums[j]);
                if (diff <= (long long int)t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};