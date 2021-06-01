#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int n = s.size();
        int maxZ = 0;
        int max1 = 0;
        int c0 = 0;
        int c1 = 0;
        char last = s[0];
        if (s[0] == '0')
        {
            c0++;
        }
        else
        {
            c1++;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == last)
            {
                if (s[i] == '1')
                {
                    c1++;
                }
                else
                {
                    c0++;
                }
            }
            else
            {
                if (last == '0')
                {
                    maxZ = max(maxZ, c0);
                    c0 = 0;
                }
                else
                {
                    max1 = max(max1, c1);
                    c1 = 0;
                }
                if (s[i] == '0')
                {
                    c0 = 1;
                    last = '0';
                }
                else
                {
                    c1 = 1;
                    last = '1';
                }
            }
        }
        if (last == '0')
        {
            maxZ = max(maxZ, c0);
            c0 = 0;
        }
        else
        {
            max1 = max(max1, c1);
            c1 = 0;
        }
        return max1 > maxZ;
    }
};