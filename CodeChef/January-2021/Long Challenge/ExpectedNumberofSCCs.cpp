#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e5 + 1;
const ll mod = (ll)998244353;
ll fact[N];

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

ll ncr(ll n, ll r)
{
    ll result = fact[n];
    ll denom = (fact[r] * fact[n - r]) % mod;
    result = (result * my_pow(denom, mod - (ll)2, mod)) % mod;
    return result;
}

ll calc(ll k, ll i)
{
    ll ans = (k * my_pow(k - 1, i - (ll)1, mod)) % mod;
    return ans;
}

ll calc2(ll k, ll i)
{
    ll ans = (k * my_pow(k, i - (ll)1, mod)) % mod;
    return ans;
}

void solve()
{
    ll m, n, k;
    cin >> m >> n >> k;
    ll num = 0;
    if (m == 1)
    {
        for (ll i = 1; i <= n; i++)
        {
            ll toAdd = ((((i) % mod * ncr(n - (ll)1, i - (ll)1)) % mod) * calc(k, i)) % mod;
            num = (num + toAdd) % mod;
        }
    }
    else
    {
    }
    ll den = my_pow(k, n * m, mod);
    den = my_pow(den, mod - (ll)2, mod);
    cout << (num % mod * den % mod) % mod << endl;
}

void solve2()
{
    ll m, n, k;
    cin >> m >> n >> k;
    ll e_v = m * n;
    ll e_e = ((n * (m - 1)) % mod + (m * (n - 1)) % mod) % mod;
    e_e = (e_e * my_pow(k, mod - 2, mod)) % mod;
    ll e_f = 1;
    if (m == 2)
    {
        e_f = (e_f + ((n - 1) * my_pow(my_pow(k, 3, mod), mod - 2, mod)) % mod) % mod;
    }
    ll ans = (e_v - e_e + mod) % mod;
    ans = (ans + e_f) % mod;
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] % mod * i % mod) % mod;
    }
    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve2();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}