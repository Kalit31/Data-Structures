#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        stack<string> temp;
        string k;
        while (ss >> k)
        {
            temp.push(k);
        }
        string ans;
        bool first = true;
        while (!temp.empty())
        {
            if (!first)
                ans += ' ';
            first = false;
            ans += temp.top();
            temp.pop();
        }
        return ans;
    }
};

class Solution
{
public:
    string reverseWords(string s)
    {
        if (s == "")
        {
            return s;
        }
        string res = "";
        while (s[0] == ' ')
        {
            s.erase(s.begin());
        }
        if (s.length() == 0)
        {
            return s;
        }
        while (s[s.length() - 1] == ' ')
        {
            s.pop_back();
        }
        if (s.length() == 0)
        {
            return s;
        }
        int i = 0;
        while (i < s.length())
        {
            string t = "";
            while (i < s.length() && s[i] != ' ')
            {
                t += s[i];
                i++;
            }
            i++;
            if (t == "")
            {
                continue;
            }
            res = t + " " + res;
        }

        return res.substr(0, res.length() - 1);
    }
};