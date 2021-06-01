#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            sum = max(sum, nums[i] + nums[n - 1 - i]);
        }
        return sum;
    }
};