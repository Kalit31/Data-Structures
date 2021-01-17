#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007;

//Binary Indexed Tree approach
class Solution
{
public:
    int c[100001];

    void update(int x)
    {
        while (x < 100001)
        {
            c[x]++;
            x += x & -x;
        }
    }

    int get(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += c[x];
            x -= x & -x;
        }
        return res;
    }

    int createSortedArray(vector<int> &instructions)
    {
        ll cost = 0;
        int n = instructions.size();
        memset(c, 0, sizeof(c));

        for (int i = 0; i < n; ++i)
        {
            cost = (cost + min(get(instructions[i] - 1), i - get(instructions[i]))) % mod;
            update(instructions[i]);
        }
        return cost;
    }
};