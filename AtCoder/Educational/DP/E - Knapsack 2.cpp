#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<array<ll, 2>> a(n);
    int max_val = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        max_val += a[i][1];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(max_val + 1, INF));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_val; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1][1] <= j)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i - 1][1]] + a[i - 1][0]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= max_val; i++)
    {
        if (dp[n][i] <= w)
        {
            ans = i;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}