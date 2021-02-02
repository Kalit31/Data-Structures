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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
    }
    ll k;
    cin >> k;
    vector<ll> c(k);
    vector<ll> d(k);
    for (int i = 0; i < k; i++)
    {
        cin >> c[i] >> d[i];
    }
    ll cases = 1ll << k;
    ll maxCond = 0;
    for (int i = 0; i < cases; i++)
    {
        vector<ll> dishes(n, 0);
        for (int j = 0; j < k; j++)
        {
            if (i & (1ll << j))
            {
                dishes[c[j] - 1]++;
            }
            else
            {
                dishes[d[j] - 1]++;
            }
        }
        ll curr = 0;
        for (int j = 0; j < m; j++)
        {
            if (dishes[a[j] - 1] >= 1 && dishes[b[j] - 1] >= 1)
            {
                curr++;
            }
        }
        maxCond = max(maxCond, curr);
    }
    cout << maxCond << endl;
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