#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        int cnt = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            cnt += nums[j] == 0;
            while (cnt > k)
            {
                cnt -= nums[i] == 0;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};