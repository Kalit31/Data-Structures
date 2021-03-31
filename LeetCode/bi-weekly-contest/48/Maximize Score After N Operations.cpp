#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<array<int, 2>, int> mp;

    int build(vector<int> &nums, int op, int mask)
    {
        if (op == ((nums.size() / 2) + 1))
        {
            return 0;
        }
        if (mp.find({op, mask}) != mp.end())
            return mp[{op, mask}];
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mask & (1 << i))
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (mask & (1 << j))
                {
                    continue;
                }
                int newMask = mask | ((1 << i) | (1 << j));
                ways = max(ways, build(nums, op + 1, newMask) + op * __gcd(nums[i], nums[j]));
            }
        }
        mp[{op, mask}] = ways;
        return ways;
    }

    int maxScore(vector<int> &nums)
    {
        return build(nums, 1, 0);
    }
};

//TLE Soln
class Solution
{
public:
    int ans = 0;

    void build(vector<int> &nums, vector<bool> visited, int currSum, int op)
    {
        if (op == ((nums.size() / 2) + 1))
        {
            ans = max(ans, currSum);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            for (int j = 0; j < nums.size(); j++)
            {
                if (visited[j])
                    continue;
                visited[j] = true;
                build(nums, visited, currSum + op * __gcd(nums[j], nums[i]), op + 1);
                visited[j] = false;
            }
            visited[i] = false;
        }
    }

    int maxScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);
        build(nums, visited, 0, 1);
        return ans;
    }
};