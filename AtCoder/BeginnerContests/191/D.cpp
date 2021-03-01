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
const ll NEGINF = -1 * INF;
using i64 = int_fast64_t;

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

//Solution by amt

template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y)
{
    assert(y != 0);
    if (y < 0)
        x = -x, y = -y;
    return x < 0 ? (x - y + 1) / y : x / y;
}

void solve()
{
    long double x, y, r;
    cin >> x >> y >> r;
    i64 xi = round(x * 1e4), yi = round(y * 1e4), ri = round(r * 1e4);
    const i64 R = 200000, t = 1e4;
    i64 ans{};
    for (auto i = -R; i <= R; ++i)
    {
        auto d = ri * ri - (i * t - xi) * (i * t - xi);
        if (d < 0)
            continue;
        i64 fsq = floor(sqrt((long double)d));
        ans += floor_div(yi + fsq, t) - floor_div(yi - fsq - 1, t);
    }
    cout << ans << "\n";
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