#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

ll build(vector<ll> &h, vector<ll> &s, map<pair<ll, ll>, ll> &m, ll bookNum, ll moneyLeft)
{
    if (moneyLeft <= 0)
    {
        return 0;
    }
    if (bookNum == h.size())
    {
        return 0;
    }
    if (m.find({bookNum, moneyLeft}) != m.end())
    {
        return m[{bookNum, moneyLeft}];
    }

    ll pagesRead = build(h, s, m, bookNum + 1, moneyLeft);
    if (moneyLeft - h[bookNum] >= 0)
        pagesRead = max(pagesRead, s[bookNum] + build(h, s, m, bookNum + 1, moneyLeft - h[bookNum]));
    m[{bookNum, moneyLeft}] = pagesRead;
    return pagesRead;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> h(n);
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    map<pair<ll, ll>, ll> m;
    //cout << build(h, s, m, 0, x) << endl;
    vector<ll> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= h[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
            cout << "dp[" << j << "]:" << dp[j] << endl;
        }
    }
    cout << dp[x] << endl;
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