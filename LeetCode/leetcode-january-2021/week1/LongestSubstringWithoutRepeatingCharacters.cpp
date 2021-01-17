#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int n = s.size();
        int maxLen = 0;
        int lPtr = 0;
        int currLen = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (m.find(ch) != m.end())
            {
                if (i - currLen <= m[ch])
                    currLen = i - m[ch];
                else
                    currLen++;
                maxLen = max(maxLen, currLen);
            }
            else
            {
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            m[ch] = i;
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};