#include <bits/stdc++.h>
using namespace std;

//Type: Bit Manipulation, Math
//Approach: Create an array of size 32,
//          to store the count of set bits at each position for every number.
//          Now for each of the ith bit, check its mod with 3.
//          If it is 0, this means that the count is a multiple of 3 or 0,
//          which indicates, the bit is not set in the required number.
//          Otherwise, the bit is set.

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<int> bits(32, 0);
        for (int i = 0; i < 32; i++)
        {
            int t = 1 << i;
            for (int j = 0; j < nums.size(); j++)
            {
                bits[i] += (nums[j] & t) != 0;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result += (bits[i] % 3) == 1 ? 1 << i : 0;
        }
        return result;
    }
};