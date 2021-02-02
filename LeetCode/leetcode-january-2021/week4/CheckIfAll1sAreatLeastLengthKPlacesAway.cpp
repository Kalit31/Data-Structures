#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] == 1)
            {
                break;
            }
            i++;
        }
        if (i == n)
        {
            return true;
        }
        int lastOne = i++;
        for (; i < n; i++)
        {
            if (nums[i] == 1)
            {
                if (i - lastOne - 1 < k)
                {
                    return false;
                }
                lastOne = i;
            }
        }
        return true;
    }
};