#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach: Start from the 0th index of the array
//          Maintain the maximum reachable distance from that cell at every index
//          If at any index, the maximum reachable distance is less than equal to current index,
//          we can not reach the end. Do handle the corner cases -> start and the last ind :)
//Complexity: O(N) time

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReachable = 0;
        if (nums.size() == 1)
        {
            return 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            if (i == nums.size() - 1)
            {
                return true;
            }
            if (maxReachable <= i)
            {
                return false;
            }
        }
        return true;
    }
};