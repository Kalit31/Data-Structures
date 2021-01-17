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
    ll n, m;
    cin >> n >> m;
    vector<vector<array<ll, 2>>> adjList(n, vector<array<ll, 2>>());
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adjList[a].push_back({c, b});
    }
    vector<ll> dist(n, INF);
    dist[0] = 0;
    vector<ll> paths(n, 0);
    paths[0] = 1;
    vector<ll> minPathsminCost(n);
    vector<ll> maxPathsminCost(n);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        array<ll, 2> curr = q.top();
        q.pop();
        ll d = curr[0];
        ll u = curr[1];
        if (d > dist[u])
        {
            continue;
        }
        for (array<ll, 2> n : adjList[u])
        {
            ll cost = n[0];
            ll v = n[1];
            if (cost + d > dist[v])
            {
                continue;
            }
            else if (cost + d == dist[v])
            {
                paths[v] = (paths[v] + paths[u]) % mod;
                minPathsminCost[v] = min(minPathsminCost[v], minPathsminCost[u] + 1);
                maxPathsminCost[v] = max(maxPathsminCost[v], maxPathsminCost[u] + 1);
            }
            else
            {

                dist[v] = cost + d;
                paths[v] = paths[u];
                minPathsminCost[v] = minPathsminCost[u] + 1;
                maxPathsminCost[v] = maxPathsminCost[u] + 1;
                q.push({dist[v], v});
            }
        }
    }
    cout << dist[n - 1] << " " << paths[n - 1] << " " << minPathsminCost[n - 1] << " " << maxPathsminCost[n - 1] << endl;
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