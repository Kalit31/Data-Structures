#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        int cnt = 0;

        while (ptr2 < n)
        {
            while (ptr2 < n && cnt <= k)
            {
                cnt += (nums[ptr2] == 0);
                if (cnt > k)
                {
                    ptr2++;
                    continue;
                }
                maxLen = max(maxLen, ptr2 - ptr1 + 1);
                ptr2++;
            }
            while (cnt > k)
            {
                cnt -= (nums[ptr1] == 0);
                ptr1++;
            }
        }

        return maxLen;
    }
};