#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        int idx = -1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                cnt++;
                idx = i;
            }
        }

        if (cnt > 1)
            return false;

        if (cnt == 0 || (idx == n - 1 || idx == 1) || (nums[idx - 1] < nums[idx + 1]) || (nums[idx - 2] < nums[idx]))
            return true;

        return false;
    }
};