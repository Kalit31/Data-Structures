#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    ll my_pow(ll a, ll n, ll m)
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
        long long int mod = 1e9 + 7;
        long long int ans = 0;
        long long int mult = 1;
        for (int i = n; i > 0; i--)
        {
            ll temp = (mult * i) % mod;
            ans = (ans + temp) % mod;
            int curr = i;
            int len = 0;
            while (curr)
            {
                curr /= 2;
                len++;
            }
            mult = (mult * my_pow(2, len, mod)) % mod;
        }
        return (int)ans;
    }
};