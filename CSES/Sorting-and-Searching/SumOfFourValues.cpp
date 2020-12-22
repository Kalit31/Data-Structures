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
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    ll t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[i] = {t, i};
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll tgt = x - a[i].first - a[j].first;
            for (int m = j + 1, k = n - 1; m < k; m++)
            {
                while (m < k && a[m].first + a[k].first > tgt)
                {
                    k--;
                }
                if (m < k && a[m].first + a[k].first == tgt)
                {
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1 << " " << a[m].second + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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