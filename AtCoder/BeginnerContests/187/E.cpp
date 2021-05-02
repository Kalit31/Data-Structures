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
    ll N;
    cin >> N;
    vector<pair<ll, ll>> edge(N - 1);
    vector<vector<ll>> g(N);
    for (ll i = 0; i < N - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = {a, b};
    }
    vector<ll> depth(N, -1);
    depth[0] = 0;
    vector<ll> q = {0};
    while (q.size())
    {
        ll at = q.back();
        q.pop_back();
        for (ll i : g[at])
            if (depth[i] == -1)
            {
                depth[i] = depth[at] + 1;
                q.push_back(i);
            }
    }
    vector<ll> s(N);
    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll t, e, x;
        cin >> t >> e >> x;
        auto [a, b] = edge[e - 1];
        if (depth[a] > depth[b])
        {
            swap(a, b);
            t ^= 3;
        }
        if (t == 1)
        {
            s[0] += x;
            s[b] -= x;
        }
        else
            s[b] += x;
    }
    q = {0};
    while (q.size())
    {
        ll at = q.back();
        q.pop_back();
        for (ll i : g[at])
            if (depth[at] < depth[i])
            {
                s[i] += s[at];
                q.push_back(i);
            }
    }
    for (ll i : s)
        cout << i << endl;
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