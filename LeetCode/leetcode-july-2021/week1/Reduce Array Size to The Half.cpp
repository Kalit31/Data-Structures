#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        map<int, int> mp;
        for (int x : arr)
        {
            mp[x]++;
        }
        vector<int> freq;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            freq.push_back(it->second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int req = n / 2;
        int have = 0;
        int cnt = 0;
        while (have < req)
        {
            have += freq[cnt];
            cnt++;
        }
        return cnt;
    }
};