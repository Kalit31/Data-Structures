#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int len = s.length();
        for (int i = len / 2; i >= 1; i--)
        {
            if (len % i == 0)
            {
                // i-> substrLen;
                int repeats = len / i;
                string substr = s.substr(0, i);
                string t = substr;
                for (int i = 1; i < repeats; i++)
                {
                    t += substr;
                }
                if (t == s)
                {
                    return true;
                }
            }
        }
        return false;
    }
};