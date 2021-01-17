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
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    unordered_set<ll> unique;
    vector<ll> ele;
    ele.push_back(0);
    /*for (int i = 0; i < n; i++)
    {
        ele.push_back(a[i]);
    }*/
    int ptr = 0;
    while (ptr != ele.size())
    {
        ll curr = ele[ptr];
        for (int i = 0; i < n; i++)
        {
            ll toFind = curr | a[i];
            if (unique.find(toFind) == unique.end())
            {
                ele.push_back(toFind);
                unique.insert(toFind);
            }
        }
        for (int i = 0; i < m; i++)
        {
            ll toFind = curr & b[i];
            if (unique.find(toFind) == unique.end())
            {
                ele.push_back(toFind);
                unique.insert(toFind);
            }
        }
        ptr++;
    }
    cout << unique.size() << endl;
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