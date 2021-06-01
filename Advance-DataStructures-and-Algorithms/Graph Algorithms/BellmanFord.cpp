#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

//Bellman Ford: O(E.V)
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

    vector<ll> dist(n, INF);
    dist[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (array<ll, 3> e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll d = e[2];
            if (dist[u] == INF)
            {
                continue;
            }
            dist[v] = min(dist[v], dist[u] + d);
            dist[v] = max(dist[v], NEGINF);
        }
    }

    //find negative cycle
    for (int i = 1; i < n; i++)
    {
        for (array<ll, 3> e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll d = e[2];
            if (dist[u] == INF)
            {
                continue;
            }
            if (dist[u] + d < dist[v])
            {
                dist[v] = NEGINF;
            }
        }
    }
}
