#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll moves = 0;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            moves += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << moves << endl;
}

int main()
{
    fast; /*
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif*/

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}