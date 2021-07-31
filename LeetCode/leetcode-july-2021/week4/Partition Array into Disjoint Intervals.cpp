#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> minNums(n);
        minNums[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            minNums[i] = min(minNums[i + 1], nums[i]);
        }

        int currMax = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (currMax <= minNums[i])
            {
                return i;
            }
            currMax = max(currMax, nums[i]);
        }
        return n;
    }
};