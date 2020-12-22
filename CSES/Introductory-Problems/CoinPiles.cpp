#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
    {
        cout << "YES" << endl;
    }
    else if (a == 0 || b == 0)
    {
        cout << "NO" << endl;
    }
    else if ((2 * a - b) >= 0 && (2 * b - a) >= 0 && (2 * a - b) % 3 == 0 && (2 * b - a) % 3 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}