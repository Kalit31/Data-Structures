#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        map<char, int> mp;
        for (char ch : s)
        {
            mp[ch]++;
        }
        int cnt = mp[s[0]];
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (cnt != it->second)
            {
                return false;
            }
        }
        return true;
    }
};