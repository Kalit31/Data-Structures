#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mp;
        vector<int> numIndex(10001, -1);
        int ptr1 = 0;
        int ptr2 = 0;

        int ans = 0;
        int currSum = 0;

        for (; ptr2 < n; ptr2++)
        {
            if (numIndex[nums[ptr2]] != -1)
            {
                int ind = numIndex[nums[ptr2]];
                while (ptr1 <= ind)
                {
                    currSum -= nums[ptr1];
                    numIndex[nums[ptr1]] = -1;
                    ptr1++;
                }
            }
            numIndex[nums[ptr2]] = ptr2;
            currSum += nums[ptr2];
            ans = max(ans, currSum);
        }
        return ans;
    }
};