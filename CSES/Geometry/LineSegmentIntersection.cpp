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

void solve()
{
    P p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    //parallel case
    if ((p2 - p1) * (p4 - p3) == 0)
    {
        if (p1.triangle(p2, p3) != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            //Bounding box approach
            for (int i = 0; i < 2; i++)
            {
                if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y))
                {
                    cout << "NO" << endl;
                    return;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
            cout << "YES" << endl;
        }
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        ll sign1 = (p2 - p1) * (p3 - p1);
        ll sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0))
        {
            cout << "NO" << endl;
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES" << endl;
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