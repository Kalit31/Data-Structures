#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum(vector<int> &nums, int div)
    {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += ceil(1.0 * nums[i] / div);
        }
        return s;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int h = 0;
        int l;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            h = max(h, nums[i]);
        }
        l = 1;
        int ans = h;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (sum(nums, mid) <= threshold)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};