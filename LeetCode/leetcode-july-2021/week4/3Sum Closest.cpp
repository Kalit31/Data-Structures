#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int toFind = target - nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                if (abs(toFind - (nums[j] + nums[k])) < diff)
                {
                    ans = nums[i] + nums[j] + nums[k];
                    diff = abs(toFind - (nums[j] + nums[k]));
                }
                if (nums[j] + nums[k] == toFind)
                {
                    return target;
                }
                else if (nums[j] + nums[k] > toFind)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};