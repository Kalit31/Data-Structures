#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    ll u, v, x;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> x;
        u--;
        v--;
        edges[i] = {u, v, x};
    }
    vector<ll> dist(n);
    vector<ll> relaxant(n, -1);
    dist[0] = 0;
    int loopNode = -1;
    for (int i = 0; i < n; i++)
    {
        loopNode = -1;
        for (array<ll, 3> e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll d = e[2];
            if (dist[u] + d < dist[v])
            {
                dist[v] = d + dist[u];
                relaxant[v] = u;
                loopNode = v;
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;*/
    if (loopNode == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            loopNode = relaxant[loopNode];
        }

        vector<int> cycle;
        for (int v = loopNode;; v = relaxant[v])
        {
            cycle.push_back(v);
            if (v == loopNode && cycle.size() > 1)
            {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (int v : cycle)
        {
            cout << v + 1 << " ";
        }
        cout << endl;
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
    return 0;
}