#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int N = 1e5 + 5;
    const int mod = 1e9 + 7;
    int sumOfFlooredPairs(vector<int> &nums)
    {
        vector<ll> prefFreq(2 * N + 1, 0);
        ll maxN = 0;
        for (int x : nums)
        {
            prefFreq[x]++;
            maxN = max(maxN, (ll)x);
        }
        for (int i = 1; i <= 2 * N; i++)
        {
            prefFreq[i] += prefFreq[i - 1];
        }

        ll sum = 0;
        for (int x : nums)
        {
            ll l = x;
            ll r = 2 * x - 1;
            ll res = 1;

            while (l <= maxN)
            {
                sum = (sum + res * (prefFreq[r] - prefFreq[l - 1])) % mod;
                l += x;
                r += x;
                res++;
            }
        }
        return sum;
    }
};