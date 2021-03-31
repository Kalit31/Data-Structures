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

ll dp[3005][3005];

ll build(vector<ll> &a, int i, int j)
{
    int n = a.size();
    if (i < 0 || j >= n || i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return a[i];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll case1 = a[i] + min(build(a, i + 2, j), build(a, i + 1, j - 1));
    ll case2 = a[j] + min(build(a, i, j - 2), build(a, i + 1, j - 1));
    return dp[i][j] = max(case1, case2);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    /* Recursive
        memset(dp, -1, sizeof(dp));
        ll X = build(a, 0, n - 1);
    */

    // Iterative
    memset(dp, 0, sizeof(dp));

    for (int diff = 0; diff < n; diff++)
    {
        for (int l = 0; l + diff < n; l++)
        {
            int r = l + diff;
            if (l == r)
            {
                dp[l][r] = a[l];
            }
            else if (l > r)
            {
                dp[l][r] = 0;
            }
            else
            {
                ll cc1 = dp[l + 2][r];
                if (r >= 1)
                    cc1 = min(cc1, dp[l + 1][r - 1]);
                else
                    cc1 = 0;
                ll c1 = a[l] + cc1;
                ll cc2;
                if (r < 2)
                {
                    cc2 = 0;
                }
                else
                {
                    cc2 = min(dp[l][r - 2], dp[l + 1][r - 1]);
                }
                ll c2 = a[r] + cc2;
                dp[l][r] = max(c1, c2);
            }
        }
    }
    ll X = dp[0][n - 1];
    ll Y = sum - X;
    cout << X - Y << endl;
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