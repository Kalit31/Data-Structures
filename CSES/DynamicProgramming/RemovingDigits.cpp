#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
#define MAX (ll)1e6

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(MAX + 1, 0);
    for (int i = 1; i <= 9; i++)
    {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++)
    {
        ll t = i;
        ll maxDigit = 0;
        while (t != 0)
        {
            maxDigit = max(maxDigit, t % 10);
            t /= 10;
        }
        dp[i] = 1 + dp[i - maxDigit];
    }
    // for (int i = 10; i <= 15; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n] << endl;
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