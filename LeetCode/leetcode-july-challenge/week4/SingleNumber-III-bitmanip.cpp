#include <bits/stdc++.h>
using namespace std;

//O(N) time compexity, O(N) space complexity
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = !m[nums[i]];
        }
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second)
            {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

//O(N) time compexity, O(1) space complexity
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto i : nums)
            ans ^= i;
        int x;
        for (int i = 0; i < 32; i++)
        {
            if (ans & (1 << i))
            {
                x = i;
                break;
            }
        }
        int a = 0, b = 0;
        for (auto i : nums)
        {
            if (i & (1 << x))
                a ^= i;
            else
                b ^= i;
        }
        return {a, b};
    }
};