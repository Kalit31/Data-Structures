#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string build(string s)
    {
        int n = s.size();
        string result = "";
        int ind = 0;
        while (ind < n && !isdigit(s[ind]))
        {
            result += s[ind];
            ind++;
        }
        if (ind == n)
        {
            return result;
        }
        string num = "";
        while (ind < n && s[ind] != '[')
        {
            num += s[ind];
            ind++;
        }
        ind++;
        string buildNxt = "";
        int cnt = 1;

        while (cnt != 0)
        {
            if (s[ind] == '[')
            {
                cnt++;
            }
            else if (s[ind] == ']')
            {
                cnt--;
            }
            if (cnt == 0)
            {
                break;
            }
            buildNxt += s[ind];
            ind++;
        }
        ind++;
        string toAdd = build(buildNxt);
        int freq = stoi(num);
        for (int i = 0; i < freq; i++)
        {
            result += toAdd;
        }
        if (ind != n)
        {
            result += build(s.substr(ind));
        }
        return result;
    }

    string decodeString(string s)
    {
        return build(s);
    }
};