#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev)
        {
            return 1;
        }
        return 2;
    }
};