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
    int n, m;
    cin >> n >> m;
    vector<array<ll, 2>> adjList[n];
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adjList[a].push_back({c, b});
    }
    for (int i = 0; i < n; i++)
    {
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
        vector<ll> dist(n, LONG_LONG_MAX);
        dist[i] = 0;
        q.push({0, i});
        set<int> processed;
        ll ans = INT_MAX;
        while (!q.empty())
        {
            array<ll, 2> curr = q.top();
            q.pop();

            if (processed.find(curr[1]) != processed.end())
            {
                continue;
            }
            for (array<ll, 2> v : adjList[curr[1]])
            {
                if (v[1] == i)
                {
                    ans = min(ans, dist[curr[1]] + v[0]);
                }
                if (dist[v[1]] > dist[curr[1]] + v[0])
                {
                    dist[v[1]] = dist[curr[1]] + v[0];
                    q.push({dist[v[1]], v[1]});
                }
            }
            processed.insert(curr[1]);
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
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