#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string originalDigits(string s)
    {
        vector<int> cnt(10, 0);
        for (char ch : s)
        {
            if (ch == 'g')
            {
                cnt[8]++;
            }
            if (ch == 'u')
            {
                cnt[4]++;
            }
            if (ch == 'w')
            {
                cnt[2]++;
            }
            if (ch == 'x')
            {
                cnt[6]++;
            }
            if (ch == 'z')
            {
                cnt[0]++;
            }
            if (ch == 'f')
            {
                cnt[5]++;
            }
            if (ch == 'h')
            {
                cnt[3]++;
            }
            if (ch == 'i')
            {
                cnt[9]++;
            }
            if (ch == 'n')
            {
                cnt[1]++;
            }
            if (ch == 's')
            {
                cnt[7]++;
            }
        }
        cnt[5] -= cnt[4];
        cnt[3] -= cnt[8];
        cnt[7] -= cnt[6];
        cnt[9] -= (cnt[5] + cnt[6] + cnt[8]);
        cnt[1] -= (2 * cnt[9] + cnt[7]);

        string result = "";
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j < cnt[i]; j++)
            {
                result += to_string(i);
            }
        }
        return result;
    }
};