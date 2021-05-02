#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        map<int, int> mp;
        for (int x : nums)
        {
            mp[x]++;
        }
        int ans = 1;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first <= 0)
            {
                continue;
            }
            if (it->first > ans)
            {
                return ans;
            }
            else if (it->first == ans)
            {
                ans++;
            }
        }

        return ans;
    }
};