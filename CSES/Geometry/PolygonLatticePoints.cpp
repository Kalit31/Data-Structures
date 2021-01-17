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

struct P
{
    ll x, y;
    void read()
    {
        cin >> x >> y;
    }
    P operator-(const P &p) const
    {
        return P{x - p.x, y - p.y};
    }
    ll operator*(const P &p) const
    {
        return x * p.y - y * p.x;
    }
    ll triangle(const P &b, const P &c) const
    {
        return (b - *this) * (c - *this);
    }
};

//Pick's Thm
// area = interior-pts + (boundary-pts/2) + 1;

void solve()
{
    int n;
    cin >> n;
    vector<P> pts(n);
    for (int i = 0; i < n; i++)
    {
        pts[i].read();
    }
    ll ptsOnBoundary = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i == n - 1 ? 0 : i + 1;
        P diff = pts[j] - pts[i];
        ll g;
        if (diff.x == 0)
        {
            g = abs(diff.y);
        }
        else if (diff.y == 0)
        {
            g = abs(diff.x);
        }
        else
        {
            g = __gcd(abs(diff.x), abs(diff.y));
        }
        ptsOnBoundary += g;
    }
    ll area = 0;
    for (int i = 1; i < n - 1; i++)
    {
        area += pts[0].triangle(pts[i], pts[i + 1]);
    }
    area = abs(area);
    ll interiorPts = area - ptsOnBoundary + 2;
    interiorPts /= 2;
    cout << interiorPts << " " << ptsOnBoundary << endl;
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