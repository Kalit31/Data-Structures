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

ll dp[1000005][2];

void pre()
{
    dp[1000001][0] = 1;
    dp[1000001][1] = 1;

    for (int i = 1000000; i >= 2; i--)
    {
        //do not extend any tile. form new tiles
        ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % mod;
        ll op2 = (dp[i + 1][0]);
        ll op3 = (2 * dp[i + 1][0]) % mod;
        ll op4 = dp[i + 1][1];

        dp[i][0] = (op1 + op2 + op3) % mod;
        dp[i][1] = (op1 + op4) % mod;
    }
}

void solve()
{
    int n;
    cin >> n;

    ll ans = (dp[1000000 - n + 2][0] + dp[1000000 - n + 2][1]) % mod;
    cout << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    pre();
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}