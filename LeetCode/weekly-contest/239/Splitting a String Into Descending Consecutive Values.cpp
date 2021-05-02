#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

class Solution
{
public:
    bool splitString(string s)
    {
        int n = s.size();
        for (int mask = 2; mask < (1 << n); mask++)
        {
            string curr = "";
            ll last = -1;
            bool poss = true;
            for (int i = 0; i < n; i++)
            {
                curr += s[i];
                if (mask & (1 << (n - i - 1)))
                {
                    ll c = stoul(curr);

                    if (last == -1)
                    {
                        last = c;
                    }
                    else
                    {
                        if (last - 1 != c)
                        {
                            poss = false;
                            break;
                        }
                        last = c;
                    }
                    curr = "";
                }
            }
            if (curr != "")
            {
                ll c = stoul(curr);
                if (last - 1 != c)
                {
                    poss = false;
                }
            }
            if (poss)
            {
                return true;
            }
        }
        return false;
    }
};