#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '0')
                {
                    cnt1++;
                }
                else
                {
                    cnt2++;
                }
            }
            else
            {
                if (s[i] == '0')
                {
                    cnt2++;
                }
                else
                {
                    cnt1++;
                }
            }
        }
        int ans = min(cnt1, cnt2);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '0')
            {
                cnt1--;
            }
            else
            {
                cnt2--;
            }
            int n1;
            int n2;
            if (n % 2 == 0)
            {
                if (ch == '1')
                {
                    n1 = cnt2 + 1;
                    n2 = cnt1;
                }
                else
                {
                    n1 = cnt2;
                    n2 = cnt1 + 1;
                }
            }
            else
            {
                if (ch == '0')
                {
                    n1 = cnt2 + 1;
                    n2 = cnt1;
                }
                else
                {
                    n1 = cnt2;
                    n2 = cnt1 + 1;
                }
            }
            cnt1 = n1;
            cnt2 = n2;
            ans = min(ans, min(cnt1, cnt2));
        }
        return ans;
    }
};