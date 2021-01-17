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
    bool operator<(const P &p) const
    {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<P> pts(n);
    for (int i = 0; i < n; i++)
    {
        pts[i].read();
    }
    sort(pts.begin(), pts.end());
    vector<P> hull;
    for (P p : pts)
    {
        while (hull.size() >= 2)
        {
            P a = hull.end()[-2];
            P b = hull.end()[-1];
            if (a.triangle(b, p) <= 0)
            {
                break;
            }
            hull.pop_back();
        }
        hull.push_back(p);
    }
    hull.pop_back();
    vector<P> tHull;

    reverse(pts.begin(), pts.end());
    for (P p : pts)
    {
        while (tHull.size() >= 2)
        {
            P a = tHull.end()[-2];
            P b = tHull.end()[-1];
            if (a.triangle(b, p) <= 0)
            {
                break;
            }
            tHull.pop_back();
        }
        tHull.push_back(p);
    }
    tHull.pop_back();
    for (P p : tHull)
    {
        hull.push_back(p);
    }
    cout << hull.size() << endl;
    for (P p : hull)
    {
        cout << p.x << " " << p.y << endl;
    }
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