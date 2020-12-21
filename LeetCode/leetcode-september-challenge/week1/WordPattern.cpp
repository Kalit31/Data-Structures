#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        int count = 0;
        stringstream t(str);
        string word;

        while (t >> word)
        {
            count++;
        }

        if (count != pattern.length())
        {
            return false;
        }

        stringstream s(str);

        unordered_map<char, string> m;
        unordered_map<string, char> m1;
        int i = 0;
        while (s >> word)
        {
            if (m.find(pattern[i]) == m.end())
            {
                m[pattern[i]] = word;
                if (m1.find(word) == m1.end())
                    m1[word] = pattern[i];
                else
                    return false;
            }
            else
            {
                if (m[pattern[i]] != word)
                {
                    return false;
                }
                if (m1[word] != pattern[i])
                {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};