#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string ans = s;
        int len = part.size();

        while (true)
        {
            int found = ans.find(part);
            if (found == string::npos)
            {
                break;
            }
            string s1 = ans.substr(0, found);
            string s2 = ans.substr(found + len);
            ans = s1 + s2;
        }
        return ans;
    }
};