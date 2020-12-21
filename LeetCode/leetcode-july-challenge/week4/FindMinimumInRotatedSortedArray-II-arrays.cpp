#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int pivot = 0, len = nums.size();
        while (pivot + 1 < len)
        {
            if (nums[pivot] <= nums[pivot + 1])
                pivot++;
            else
                return nums[pivot + 1];
        }
        return nums[0];
    }
};