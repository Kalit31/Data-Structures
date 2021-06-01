#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atmostK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        int ptr1 = 0;
        int ptr2 = 0;

        while (ptr2 < n)
        {
            k -= nums[ptr2] % 2;
            while (k < 0)
            {
                k += nums[ptr1] % 2;
                ptr1++;
            }
            cnt += (ptr2 - ptr1 + 1);
            ptr2++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int ans = atmostK(nums, k) - atmostK(nums, k - 1);
        return ans;
    }
};