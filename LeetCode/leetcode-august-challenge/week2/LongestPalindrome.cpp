#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        int len = 0;
        int totalOdd = 0;
        bool oddPresent = false;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second % 2 == 0)
            {
                len += it->second;
            }
            else
            {
                oddPresent = true;
                totalOdd += it->second - 1;
                //maxOddLen = max(maxOddLen,it->second);
            }
        }
        // cout<<"LEN: "<<len<<endl;
        // cout<<"MAX:"<<maxOddLen<<endl;
        // if(maxOddLen!=INT_MIN){
        //     len += maxOddLen;
        // }
        if (oddPresent)
            len += totalOdd + 1;
        return len;
    }
};