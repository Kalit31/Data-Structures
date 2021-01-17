#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool check(vector<ll> &k, ll t, ll time)
{
    ll ans = 0;
    for (int i = 0; i < k.size(); i++)
    {
        ans += time / k[i];
    }

    return ans < 0 || ans >= t;
}

void solve()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> k(n);
    ll l = 1;
    ll h = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        h = max(h, k[i]);
    }
    h = h * t;
    ll ans = h;
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        if (check(k, t, mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
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

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}