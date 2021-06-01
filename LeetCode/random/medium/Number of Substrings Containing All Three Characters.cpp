#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int a = 0;
        int b = 0;
        int c = 0;

        int ptr1 = 0;
        int ptr2 = 0;

        int ans = 0;

        while (ptr2 < n)
        {
            if (s[ptr2] == 'a')
            {
                a++;
            }
            else if (s[ptr2] == 'b')
            {
                b++;
            }
            else
            {
                c++;
            }
            while (a > 0 && b > 0 && c > 0)
            {
                ans += s.length() - ptr2;
                if (s[ptr1] == 'a')
                {
                    a--;
                }
                else if (s[ptr1] == 'b')
                {
                    b--;
                }
                else
                {
                    c--;
                }
                ptr1++;
            }
            ptr2++;
        }
        return ans;
    }
};