#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0;
        int maxFreq = 1;

        long sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += nums[j];
            while (sum + k < (long)nums[j] * (j - i + 1))
            {
                sum -= nums[i];
                i++;
            }
            maxFreq = max(maxFreq, j - i + 1);
        }
        return maxFreq;
    }
};