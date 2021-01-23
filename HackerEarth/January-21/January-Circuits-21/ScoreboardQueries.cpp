#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << n + 1 << endl;
    }
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