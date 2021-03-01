#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brokenCalc(int x, int y)
    {
        if (x == y)
        {
            return 0;
        }
        if (x > y)
        {
            return x - y;
        }
        if (y % 2 == 0)
        {
            return 1 + brokenCalc(x, y / 2);
        }
        else
        {
            return 1 + brokenCalc(x, y + 1);
        }
    }
};

// Similar to AtCoder 188 Pblm F

class Solution
{
public:
    int x, y, ans;
    map<int, int> vis, cache;

    int recurse(int val)
    {
        if (vis[val])
            return cache[val];
        vis[val] = 1;
        cache[val] = 1e9 + 5;
        int &ans = cache[val];
        if (x >= val)
            ans = min(ans, x - val);
        if (val == 1)
            return ans;
        if (val % 2 == 0)
            ans = min(ans, 1 + recurse(val / 2));
        else
            ans = min(ans, 1 + recurse(val + 1));
        return ans;
    }

    int brokenCalc(int X, int Y)
    {
        x = X;
        y = Y;
        if (x >= y)
            ans = x - y;
        return recurse(y);
    }
};