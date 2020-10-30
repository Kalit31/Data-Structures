#include <bits/stdc++.h>
using namespace std;
#define mod 10000007

class Solution
{
public:
    bool match(string s, int subLen, string &res, vector<int> &roll)
    {
        unordered_map<int, vector<int>> m;
        int hash = 0;
        for (int i = 0; i < subLen; i++)
        {
            hash = (hash * 26 + (s[i] - 'a')) % mod;
        }
        m[hash].push_back(0);
        for (int j = subLen; j < s.size(); j++)
        {
            hash = ((hash - roll[subLen - 1] * (s[j - subLen] - 'a')) % mod + mod) % mod;
            hash = (hash * 26 + (s[j] - 'a')) % mod;

            if (m.find(hash) != m.end())
            {
                for (auto start : m[hash])
                {
                    string temp = s.substr(start, subLen);
                    string curr = s.substr(j - subLen + 1, subLen);
                    if (temp.compare(curr) == 0)
                    {
                        res = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j - subLen + 1);
        }
        return false;
    }

    string longestDupSubstring(string S)
    {
        int n = S.size();
        vector<int> roll(n, 1);
        for (int i = 1; i < n; i++)
        {
            roll[i] = (roll[i - 1] * 26) % mod;
        }
        int l = 1;
        int h = n;
        string result = "";
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            string temp = " ";
            bool flag = match(S, mid, temp, roll);
            if (flag)
            {
                if (temp.size() > result.size())
                {
                    result = temp;
                }
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return result;
    }
};