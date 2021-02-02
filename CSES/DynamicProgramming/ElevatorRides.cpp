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
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    ll subsets = 1ll << n;
    vector<array<ll, 2>> dp(subsets);
    dp[0] = {1, 0};
    for (int s = 1; s < subsets; s++)
    {
        dp[s] = {n + 1, 0};
        for (int p = 0; p < n; p++)
        {
            if (s & (1 << p))
            {
                //excluding the person p, find options
                auto opt = dp[s ^ (1 << p)];
                if (opt[1] + w[p] <= x)
                {
                    opt[1] += w[p];
                }
                else
                {
                    opt[0]++;
                    opt[1] = w[p];
                }
                dp[s] = min(dp[s], opt);
            }
        }
    }
    cout << dp[subsets - 1][0] << endl;
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