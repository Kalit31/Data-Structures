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
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    //dp[i][j] is the probability of having j heads on the first i coins
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[1][0] = 1 - p[0];
    dp[1][1] = p[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (1 - p[i - 1]) * dp[i - 1][0];
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = p[i - 1] * dp[i - 1][j - 1] + (1 - p[i - 1]) * dp[i - 1][j];
        }
    }

    double ans = 0;
    for (int i = n; i >= ((n + 1) / 2); i--)
    {
        ans += dp[n][i];
    }
    cout << setprecision(20) << ans << endl;
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