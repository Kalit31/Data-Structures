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

ll dp[101][100005];

ll build(vector<int> &a, int k, int curr)
{
    int n = a.size();
    if (k == 0 && curr == -1)
    {
        return 1;
    }
    else if (curr < 0)
    {
        return 0;
    }
    if (dp[curr][k] != -1)
    {
        return dp[curr][k];
    }

    ll ways = 0;
    for (int i = 0; i <= a[curr]; i++)
    {
        if (i <= k)
        {
            ways = (ways + build(a, k - i, curr - 1)) % mod;
        }
        else
        {
            break;
        }
    }
    return dp[curr][k] = ways;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*
    Recursive
    memset(dp, -1, sizeof(dp));
    cout << build(a, k, n - 1) << endl;    
    */

    for (int i = 0; i <= a[0]; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> pref(k + 1);
        pref[0] = dp[i - 1][0];
        for (int j = 1; j < k + 1; j++)
        {
            pref[j] = (pref[j - 1] + dp[i - 1][j]) % mod;
        }
        for (int j = 0; j <= k; j++)
        {
            if (j > a[i])
            {
                dp[i][j] = (pref[j] - pref[j - a[i] - 1] + mod) % mod;
            }
            else
            {
                dp[i][j] = pref[j];
            }
        }
    }

    cout << dp[n - 1][k] << endl;
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