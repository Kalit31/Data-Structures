#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int value(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }

    int romanToInt(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (i != n - 1)
            {
                if (ch == 'I')
                {
                    if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    {
                        ans += value(s[i + 1]);
                        ans -= value(ch);
                        i++;
                    }
                    else
                    {
                        ans += value(ch);
                    }
                }
                else if (ch == 'X')
                {
                    if (s[i + 1] == 'L' || s[i + 1] == 'C')
                    {
                        ans += value(s[i + 1]);
                        ans -= value(ch);
                        i++;
                    }
                    else
                    {
                        ans += value(ch);
                    }
                }
                else if (ch == 'C')
                {
                    if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    {
                        ans += value(s[i + 1]);
                        ans -= value(ch);
                        i++;
                    }
                    else
                    {
                        ans += value(ch);
                    }
                }
                else
                {
                    ans += value(ch);
                }
            }
            else
            {
                ans += value(ch);
            }
        }
        return ans;
    }
};