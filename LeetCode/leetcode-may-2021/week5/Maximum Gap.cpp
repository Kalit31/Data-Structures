#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        int minN = *min_element(nums.begin(), nums.end());
        int maxN = *max_element(nums.begin(), nums.end());

        //this is the minimum possible value of the maximum gap
        int gap = ceil((1.0 * (maxN - minN)) / (n - 1));

        vector<int> bucketMin(n - 1, INT_MAX);
        vector<int> bucketMax(n - 1, INT_MIN);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == minN || nums[i] == maxN)
            {
                continue;
            }
            int idx = (nums[i] - minN) / gap;
            bucketMin[idx] = min(bucketMin[idx], nums[i]);
            bucketMax[idx] = max(bucketMax[idx], nums[i]);
        }
        int maxGap = gap;
        int prev = minN;
        for (int i = 0; i < n - 1; i++)
        {
            if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN)
            {
                continue;
            }
            maxGap = max(maxGap, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        maxGap = max(maxGap, maxN - prev);
        return maxGap;
    }
};

//Naive solution
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int diff = 0;
        for (int i = 0; i < n - 1; i++)
        {
            diff = max(diff, nums[i + 1] - nums[i]);
        }
        return diff;
    }
};