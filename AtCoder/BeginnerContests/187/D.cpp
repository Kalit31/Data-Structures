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

bool comp(array<ll, 2> &a, array<ll, 2> &b)
{
    return (2 * a[0] + a[1]) > (2 * b[0] + b[1]);
}

void solve()
{
    ll n;
    cin >> n;
    vector<array<ll, 2>> t(n);
    ll a = 0;
    ll b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i][0] >> t[i][1];
        a += t[i][0];
    }
    sort(t.begin(), t.end(), comp);
    /*for (int i = 0; i < n; i++)
    {
        cout << t[i][0] << " " << t[i][1] << endl;
    }*/
    int cnt = 0;
    while (a >= b)
    {
        b += t[cnt][0] + t[cnt][1];
        a -= t[cnt][0];
        cnt++;
    }
    cout << cnt << endl;
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