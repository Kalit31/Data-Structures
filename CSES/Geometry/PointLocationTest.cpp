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
};

void solve()
{

    /*ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ll del_y = y2 - y1;
    ll del_x = x2 - x1;
    ll del_py = y3 - y1;
    ll del_px = x3 - x1;
    ll diff = del_py * del_x - del_px * del_y;*/
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p3 = p3 - p1;
    p2 = p2 - p1;
    ll diff = p3.y * p2.x - p3.x * p2.y;
    if (diff == 0)
    {
        cout << "TOUCH" << endl;
    }
    else if (diff > 0)
    {
        cout << "LEFT" << endl;
    }
    else
    {
        cout << "RIGHT" << endl;
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}