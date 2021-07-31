#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    ll modpow(ll a, ll n, ll mod)
    {
        ll result = 1;

        while (n)
        {
            if (n & 1)
            {
                result = (result * a) % mod;
                n--;
            }
            a = (a * a) % mod;
            n /= 2;
        }

        return result;
    }
    int countGoodNumbers(long long n)
    {
        const int mod = 1e9 + 7;
        ll evenInd = n / 2 + (n & 1);
        ll oddInd = n - evenInd;
        ll ans = (modpow(5LL, evenInd, mod) * modpow(4LL, oddInd, mod)) % mod;
        return ans;
    }
};