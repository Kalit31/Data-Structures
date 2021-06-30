#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int side = 0;
    bool build(vector<int> &matchsticks, int ind, int a, int b, int c, int d)
    {
        if (ind == matchsticks.size())
        {
            if (a == b && b == c && c == d)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (a + matchsticks[ind] <= side && build(matchsticks, ind + 1, a + matchsticks[ind], b, c, d))
        {
            return true;
        }
        if (b + matchsticks[ind] <= side && build(matchsticks, ind + 1, a, b + matchsticks[ind], c, d))
        {
            return true;
        }
        if (c + matchsticks[ind] <= side && build(matchsticks, ind + 1, a, b, c + matchsticks[ind], d))
        {
            return true;
        }
        if (d + matchsticks[ind] <= side && build(matchsticks, ind + 1, a, b, c, d + matchsticks[ind]))
        {
            return true;
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int total = 0;
        for (int x : matchsticks)
        {
            total += x;
        }
        if (total % 4 != 0)
        {
            return false;
        }
        side = total / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return build(matchsticks, 0, 0, 0, 0, 0);
    }
};