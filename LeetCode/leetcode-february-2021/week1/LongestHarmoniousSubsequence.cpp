#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        int maxLen = 0;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            int num = it->first;
            if (freq.find(num - 1) != freq.end())
            {
                maxLen = max(maxLen, freq[num] + freq[num - 1]);
            }
            if (freq.find(num + 1) != freq.end())
            {
                maxLen = max(maxLen, freq[num] + freq[num + 1]);
            }
        }
        return maxLen;
    }
};