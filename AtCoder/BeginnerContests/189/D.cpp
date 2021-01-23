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

map<int, ll> mTrue, mFalse;
ll buildTrue(vector<bool> &a, int curr);

ll buildFalse(vector<bool> &a, int curr)
{
    int n = a.size();
    if (curr == 0)
    {
        if (a[curr])
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    if (mFalse.find(curr) != mFalse.end())
    {
        return mFalse[curr];
    }
    ll cnt = 0;
    if (a[curr])
    {
        cnt += buildFalse(a, curr - 1);
    }
    else
    {
        cnt += 2 * buildFalse(a, curr - 1);
        cnt += buildTrue(a, curr - 1);
    }
    mFalse[curr] = cnt;
    return cnt;
}

ll buildTrue(vector<bool> &a, int curr)
{
    int n = a.size();
    if (curr == 0)
    {
        if (a[curr])
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
    if (mTrue.find(curr) != mTrue.end())
    {
        return mTrue[curr];
    }
    ll cnt = 0;
    if (a[curr])
    {
        cnt += buildFalse(a, curr - 1);
        cnt += 2 * buildTrue(a, curr - 1);
    }
    else
    {
        cnt += buildTrue(a, curr - 1);
    }
    mTrue[curr] = cnt;
    return cnt;
}

void solve()
{
    ll n;
    cin >> n;
    vector<bool> a(n);
    string t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == "AND")
        {
            a[i] = false;
        }
        else
        {
            a[i] = true;
        }
    }
    ll cnt = buildTrue(a, n - 1);
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}