#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll minB = 2 * n - 1;
    ll maxB = (n * (n + 1)) / 2;
    if (m < minB || m > maxB)
    {
        cout << -1 << endl;
        return;
    }
    ll v = 1;
    ll parent = -1;
    ll left = n;
    while (m != 0)
    {
        if (m > minB && m <= maxB)
        {
            m -= left;
            if (parent != -1)
                cout << parent << " " << v << endl;
            parent = v++;
            left--;
            minB = 2 * left - 1;
            maxB = (left * (left + 1)) / 2;
        }
        else if (m == minB)
        {
            m = 0;
            if (parent != -1)
                cout << parent << " " << v << endl;
            parent = v++;
            while (v <= n)
            {
                cout << parent << " " << v++ << endl;
            }
        }
        else
        {
            cout << parent << " " << v++ << endl;
            m--;
            left--;
            minB = 2 * left - 1;
            maxB = (left * (left + 1)) / 2;
        }
    }
}

int main()
{
    ll T = 1;
    while (T--)
    {
        solve();
    }
}