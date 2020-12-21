#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;

        m[nums[0]] = 1;

        int count = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (m[nums[i]] == 0 || (k == 0 && m[nums[i]] == 1))
            {
                if (m[nums[i] - k])
                {
                    count++;
                }
                m[nums[i]]++;
            }
        }
        return count;
    }
};