#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string result = "";
        int i = 0;
        int n = s.size();

        while (i < n)
        {
            if (s[i] == '(')
            {
                i++;
                string key = "";
                while (s[i] != ')')
                {
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end())
                {
                    result += mp[key];
                }
                else
                {
                    result += '?';
                }
                i++;
            }
            else
            {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};