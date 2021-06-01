#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swaps(string s, string result)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != result[i])
            {
                cnt++;
            }
        }
        return cnt;
    }

    int minSwaps(string s)
    {
        int n = s.size();
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
        }
        if (abs(cnt0 - cnt1) > 1)
        {
            return -1;
        }
        string result = "";
        int cnt = 0;
        if (cnt0 > cnt1)
        {
            for (int i = 0; i < n; i++)
            {
                result += i % 2 == 0 ? '0' : '1';
            }
            cnt = swaps(s, result);
        }
        else if (cnt0 < cnt1)
        {
            for (int i = 0; i < n; i++)
            {
                result += i % 2 == 1 ? '0' : '1';
            }
            cnt = swaps(s, result);
        }
        else
        {
            string result1 = "";
            for (int i = 0; i < n; i++)
            {
                result1 += i % 2 == 1 ? '0' : '1';
            }
            string result2 = "";
            for (int i = 0; i < n; i++)
            {
                result2 += i % 2 == 0 ? '0' : '1';
            }
            cnt = min(swaps(s, result1), swaps(s, result2));
        }
        return cnt / 2;
    }
};