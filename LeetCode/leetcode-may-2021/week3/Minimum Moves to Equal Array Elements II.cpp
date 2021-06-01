#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median;
        if (n % 2 == 0)
        {
            median = (nums[n / 2] + nums[(n - 1) / 2]) / 2;
        }
        else
        {
            median = nums[n / 2];
        }
        int moves = 0;
        for (int i = 0; i < n; i++)
        {
            moves += abs(median - nums[i]);
        }
        return moves;
    }
};