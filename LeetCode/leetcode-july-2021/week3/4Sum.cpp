#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> uniqueQuad;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int req = target - nums[i] - nums[j];
                for (int k = j + 1, l = n - 1; k < n; k++)
                {
                    while (k < l && nums[k] + nums[l] > req)
                    {
                        l--;
                    }
                    if (k < l && nums[k] + nums[l] == req)
                    {
                        uniqueQuad.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto it : uniqueQuad)
        {
            result.push_back((it));
        }
        return result;
    }
};