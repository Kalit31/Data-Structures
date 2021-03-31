#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = nums[k];
        int ptr1 = k - 1;
        int ptr2 = k + 1;
        int i = k;
        int j = k;
        int currMin = nums[k];

        while (ptr1 >= 0 && ptr2 < n)
        {
            if (nums[ptr1] >= nums[ptr2])
            {
                currMin = min(currMin, nums[ptr1]);
                i = ptr1;
                ans = max(ans, currMin * (j - i + 1));
                ptr1--;
            }
            else
            {
                currMin = min(currMin, nums[ptr2]);
                j = ptr2;
                ans = max(ans, currMin * (j - i + 1));
                ptr2++;
            }
        }

        while (ptr1 >= 0)
        {
            currMin = min(currMin, nums[ptr1]);
            i = ptr1;
            ans = max(ans, currMin * (j - i + 1));
            ptr1--;
        }

        while (ptr2 < n)
        {
            currMin = min(currMin, nums[ptr2]);
            j = ptr2;
            ans = max(ans, currMin * (j - i + 1));
            ptr2++;
        }
        return ans;
    }
};