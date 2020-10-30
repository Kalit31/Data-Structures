#include <bits/stdc++.h>
using namespace std;

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