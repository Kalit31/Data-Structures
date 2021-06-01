#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e15;

//O(V^3) Floyd Warshall algorithm
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    ll u, v, c;

    for (int i = 0; i < n; i++)
    {
        adj[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        u--;
        v--;
        adj[u][v] = adj[v][u] = min(c, adj[u][v]);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    //Queries...
}
