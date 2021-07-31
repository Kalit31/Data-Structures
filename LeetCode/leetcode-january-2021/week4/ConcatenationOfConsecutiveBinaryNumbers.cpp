#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    ll modpow(ll a, ll n, ll m)
    {
        ll res = 1;
        while (n)
        {
            if (n % 2)
            {
                res = (res * a) % m;
                n--;
            }
            a = (a * a) % m;
            n /= 2;
        }
        return res;
    }

    int concatenatedBinary(int n)
    {
        const int mod = 1e9 + 7;
        ll ans = 0;
        ll mult = 1;
        for (int i = 1; i <= n; i++)
        {
            int len = 0;
            int curr = i;
            while (curr)
            {
                len++;
                curr /= 2;
            }
            ans = (ans * modpow(2, len, mod)) % mod;
            ans = (ans + i) % mod;
        }
        return (int)ans;
    }
};