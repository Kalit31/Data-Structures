#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int slowPtr = nums[0];
        int fastPtr = nums[0];
        do
        {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        slowPtr = nums[0];
        while (slowPtr != fastPtr)
        {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }
        return slowPtr;
    }
};