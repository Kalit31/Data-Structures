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
    if (n > 1 && n <= 3)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (n & 1)
    {
        for (ll i = n - 1; i >= 2; i = i - 2)
        {
            cout << i << " ";
        }
        for (ll i = n; i >= 1; i = i - 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        for (ll i = n - 1; i >= 1; i = i - 2)
        {
            cout << i << " ";
        }
        for (ll i = n; i >= 2; i = i - 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}