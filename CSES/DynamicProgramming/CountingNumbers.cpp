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

ll dp[20][10][2][2];

ll build(string &num, ll n, ll x, bool leadingZero, bool tight)
{
    if (n == 0)
    {
        return 1;
    }
    if (x != -1 && dp[n][x][leadingZero][tight] != -1)
    {
        return dp[n][x][leadingZero][tight];
    }
    int lb = 0;
    int ub = tight ? (num[num.size() - n] - '0') : 9;
    ll ans = 0;
    for (int dig = lb; dig <= ub; dig++)
    {
        if (dig == x && !leadingZero)
        {
            continue;
        }
        ans += build(num, n - 1, dig, (leadingZero & dig == 0), (tight & dig == ub));
    }
    return dp[n][x][leadingZero][tight] = ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    string A = to_string(a - 1);
    ll ansA = build(A, A.size(), -1, true, true);
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ansB = build(B, B.size(), -1, true, true);
    cout << ansB - ansA << endl;
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