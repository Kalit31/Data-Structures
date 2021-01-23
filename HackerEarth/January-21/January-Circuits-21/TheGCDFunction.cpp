// Write your code here
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll f = n * (n + 1);
    f /= 2;
    ll x = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (x % i == 0)
        {
            continue;
        }
        else
        {
            ll g = __gcd(x, i);
            x = x * (i / g);
        }
    }
    cout << f << " " << x << endl;
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}