#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
        {
            return 0;
        }
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        int cnt = 0;
        for (ll i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                cnt++;
                for (ll j = (ll)i * (ll)i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return cnt;
    }
};