#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 0)
        {
            return 0;
        }
        long long int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        if (s[0] == '0')
        {
            return 0;
        }
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            // check for 1 digit. if valid, possible cases = possible cases excluding it.
            if (s[i - 1] > '0')
            {
                dp[i] = dp[i - 1];
            }
            // check for 2 digits. if valid, possible cases = possible cases excluding the 2 digits.
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
            {
                dp[i] = (dp[i] + dp[i - 2]);
            }
        }
        return (dp[n]);
    }
};

//More efficient
class Solution
{
public:
    unordered_map<int, int> store;

    int Permute(string &s, int l)
    {
        int res = 0;
        if (l == s.size())
        {
            return 1;
        }

        if (s[l] == 0 or s[l] == '0')
            return 0;

        if (l == s.size() - 1)
        {
            return 1;
        }

        if (store.find(l) != store.end())
            return store[l];

        res += Permute(s, l + 1);
        if (((s[l] - '0') * 10) + (s[l + 1] - '0') <= 26)
        {
            res += Permute(s, l + 2);
        }

        store.emplace(l, res);

        return res;
    }

    int numDecodings(string s)
    {
        int res = 0;
        if (s.size())
            res = Permute(s, 0);
        return res;
    }
};