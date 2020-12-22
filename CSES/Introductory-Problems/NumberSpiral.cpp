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
    ll y, x;
    cin >> y >> x;
    ll side = max(x, y);
    ll num = (side - 1) * (side - 1);
    ll ans;
    if (side % 2)
    {
        if (side == y)
        {
            ans = num + x;
        }
        else
        {
            ans = num + 2 * side - y;
        }
    }
    else
    {
        if (side == x)
        {
            ans = num + y;
        }
        else
        {
            ans = num + 2 * side - x;
        }
    }
    cout << ans << endl;
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