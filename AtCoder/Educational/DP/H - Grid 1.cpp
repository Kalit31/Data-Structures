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
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;
    for (int i = 1; i < h; i++)
    {
        if (grid[i][0] == '#')
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < w; i++)
    {
        if (grid[0][i] == '#')
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else
            {
                if (grid[i - 1][j] == '.')
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                }
                if (grid[i][j - 1] == '.')
                {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
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