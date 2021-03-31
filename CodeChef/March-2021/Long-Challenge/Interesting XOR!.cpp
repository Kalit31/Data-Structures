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
const ll NEGINF = -1 * INF;

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
    ll c;
    cin >> c;
    int d = 0;
    ll tmp = c;
    while (tmp)
    {
        tmp /= 2;
        d++;
    }
    ll a = 0;
    ll b = 0;
    tmp = c;
    vector<int> ind;
    for (int i = 0; i < d; i++)
    {
        if ((c & (1 << i)) == 0)
        {
            a += (1 << i);
            b += (1 << i);
        }
        else
        {
            ind.push_back(i);
        }
    }
    int n = ind.size();
    a += 1 << ind.back();
    for (int i = 0; i < n - 1; i++)
    {
        b += 1 << ind[i];
    }
    ll ans = a * b;
    // for (ll i = 0; i < 1 << n; i++)
    // {
    //     ll currA = a;
    //     ll currB = b;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i & (1 << j))
    //         {
    //             currA += (1 << ind[j]);
    //         }
    //         else
    //         {
    //             currB += (1 << ind[j]);
    //         }
    //         ans = max(ans, currA * currB);
    //     }
    // }
    cout << ans << endl;
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