#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(string &s)
    {
        int cnt = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                cnt++;
            }
            else
            {
                if (cnt == 0)
                {
                    return false;
                }
                cnt--;
            }
        }
        return cnt == 0;
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string s(2 * n, '.');
        for (int mask = 0; mask < (1 << (2 * n)); mask++)
        {
            for (int i = 0; i < 2 * n; i++)
            {
                if (mask & (1 << i))
                {
                    s[i] = '(';
                }
                else
                {
                    s[i] = ')';
                }
            }
            if (check(s))
            {
                result.push_back(s);
            }
        }
        return result;
    }
};

//Another approach using backtracking