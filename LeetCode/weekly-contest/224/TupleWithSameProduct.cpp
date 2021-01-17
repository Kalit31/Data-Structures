#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                m[nums[i] * nums[j]]++;
            }
        }
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second >= 2)
            {
                int x = it->second;
                int choice = ((x) * (x - 1)) / 2;
                cnt += 8 * choice;
            }
        }
        return cnt;
    }
};