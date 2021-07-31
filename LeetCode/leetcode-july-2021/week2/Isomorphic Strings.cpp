#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        map<char, char> mp;
        map<char, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                s[i] = mp[s[i]];
                if (s[i] != t[i])
                {
                    return false;
                }
            }
            else
            {
                if (visited[t[i]])
                {
                    return false;
                }
                mp[s[i]] = t[i];
                visited[t[i]] = true;
            }
        }
        return true;
    }
};