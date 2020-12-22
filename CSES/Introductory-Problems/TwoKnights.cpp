#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
ll solve(ll i, ll j, ll n)
{
    ll ans = 0;
    //1
    if (i - 2 > 0 && j - 1 > 0)
    {
        ans++;
    }
    //2
    if (i - 1 > 0 && j - 2 > 0)
    {
        ans++;
    }
    //3
    if (i - 2 > 0 && j + 1 <= n)
    {
        ans++;
    }
    //4
    if (i - 1 > 0 && j + 2 <= n)
    {
        ans++;
    }
    //5
    if (i + 2 <= n && j - 1 > 0)
    {
        ans++;
    }
    //6
    if (i + 1 <= n && j - 2 > 0)
    {
        ans++;
    }
    //7
    if (i + 2 <= n && j + 1 <= n)
    {
        ans++;
    }
    //8
    if (i + 1 <= n && j + 2 <= n)
    {
        ans++;
    }
    return ans;
}

ll calc(ll n)
{
    ll ans = ((n * n) * ((n * n) - 1)) / 2;
    ll sub = 4 * (n - 2) * (n - 1);
    /* for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            sub += solve(i, j, n);
        }
    }*/
    //deb(sub);
    ans = ans - sub;
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cout << calc(i) << endl;
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
    while (T--)
    {
        solve();
    }
    return 0;
}