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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
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

struct comp
{
    bool operator()(const array<ll, 2> &a, array<ll, 2> &b)
    {
        return a[1] > b[1];
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<ll, 2>> bag(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bag[i][0] >> bag[i][1];
    }
    sort(bag.begin(), bag.end(), comp());

    vector<ll> box(m);
    for (int i = 0; i < m; i++)
    {
        cin >> box[i];
    }

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        vector<ll> sizes;
        for (int i = 0; i < l; i++)
        {
            sizes.pb(box[i]);
        }
        for (int i = r + 1; i < m; i++)
        {
            sizes.pb(box[i]);
        }
        ll val = 0;
        int i = 0;

        sort(sizes.begin(), sizes.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < sizes.size(); j++)
            {
                if (sizes[j] != -1 && bag[i][0] <= sizes[j])
                {
                    sizes[j] = -1;
                    val += bag[i][1];
                    break;
                }
            }
        }
        cout << val << endl;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}