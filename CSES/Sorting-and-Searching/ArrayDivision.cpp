#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool check(vector<ll> &x, ll sum, ll k)
{
    ll subs = 1;
    ll s = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > sum)
        {
            return false;
        }
        s += x[i];
        if (s > sum)
        {
            s = x[i];
            subs++;
        }
    }
    //deb(subs);
    return subs <= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    ll l = 0;
    ll h = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        l = max(l, x[i]);
        h += x[i];
    }
    ll ans = h;
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        // deb(mid);
        if (check(x, mid, k))
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