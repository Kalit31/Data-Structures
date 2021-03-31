#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;

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

    int maxNiceDivisors(int primeFactors)
    {
        if (primeFactors <= 3)
        {
            return primeFactors;
        }
        if (primeFactors % 3 == 0)
        {
            return my_pow(3, primeFactors / 3, mod);
        }
        else if (primeFactors % 3 == 1)
        {
            return (my_pow(3, (primeFactors - 4) / 3, mod) * 4) % mod;
        }
        else
        {
            return (my_pow(3, (primeFactors - 2) / 3, mod) * 2) % mod;
        }
        return 1;
    }
};