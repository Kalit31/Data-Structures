#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<array<ll, 2>> dp(1ll << n);
    /*
        dp[mask] = {a,b};
        'a' denotes minimum number of rides for a subset 'mask'
        'b' denotes minimum weight of the last ride
    */
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1ll < n); mask++)
    {
        dp[mask] = {n + 1, 0};
        for (int p = 0; p < n; p++)
        {
            if (mask & (1 << p))
            {
                //excluding the person p, find options
                auto opt = dp[mask ^ (1 << p)];
                if (opt[1] + w[p] <= x)
                {
                    opt[1] += w[p];
                }
                else
                {
                    opt[0]++;
                    opt[1] = w[p];
                }
                dp[mask] = min(dp[mask], opt);
            }
        }
    }
    cout << dp[(1ll << n) - 1][0] << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}