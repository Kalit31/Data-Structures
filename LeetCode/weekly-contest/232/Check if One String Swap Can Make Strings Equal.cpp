#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        int i1 = -1;
        int i2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                if (i1 == -1)
                {
                    i1 = i;
                }
                else if (i2 == -1)
                {
                    i2 = i;
                }
                else
                {
                    return false;
                }
            }
        }
        if (i1 == -1 && i2 == -1)
        {
            return true;
        }
        else if (i1 != -1 && i2 != -1)
        {
            swap(s1[i1], s1[i2]);
            return s1 == s2;
        }
        return false;
    }
};