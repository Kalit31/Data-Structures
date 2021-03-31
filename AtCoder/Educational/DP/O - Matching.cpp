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

ll ways = 0;
void build(int curr, int mask, vector<vector<int>> &a)
{
    int n = a.size();
    if (curr == n)
    {
        ways = (ways + 1) % mod;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (a[curr][j])
        {
            if ((mask & (1 << j)) == 0)
            {
                build(curr + 1, mask | (1 << j), a);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    /*  Recursive soln

        ways = 0;
        build(0, 0, a);
        cout << ways << endl;
    
    */

    vector<ll> dp(1 << n);
    dp[0] = 1;

    for (ll mask = 0; mask < (1 << n) - 1; mask++)
    {
        //0 to (i-1) men have paired with the i women
        int i = __builtin_popcount(mask);
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] && (mask & (1 << j)) == 0)
            {
                dp[mask | (1 << j)] = (dp[mask] + dp[mask | (1 << j)]) % mod;
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
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