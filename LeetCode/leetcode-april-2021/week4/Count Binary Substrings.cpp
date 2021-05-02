#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cntStrings(string &s, int i, int j)
    {
        int n = s.size();
        int cnt = 0;

        while (i >= 0 && j < n)
        {
            cnt++;
            if (i > 0 && s[i] != s[i - 1])
            {
                break;
            }
            if (j + 1 < n && s[j] != s[j + 1])
            {
                break;
            }
            i--;
            j++;
        }

        return cnt;
    }

    int countBinarySubstrings(string s)
    {
        int cnt = 0;
        int n = s.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                cnt += cntStrings(s, i, i + 1);
            }
        }
        return cnt;
    }
};