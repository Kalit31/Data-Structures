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

/*
    vector<array<ll, 2>> adjList[n];
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    vector<ll> dist(n, LONG_LONG_MAX);
    dist[0] = 0;
    q.push({0, 0});
    set<int> processed;
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
            if (dist[v[1]] > dist[curr[1]] + v[0])
            {
                dist[v[1]] = dist[curr[1]] + v[0];
                q.push({dist[v[1]], v[1]});
            }
        }
        processed.insert(curr[1]);
    }
*/

//Single Source K shortest paths. Dijkstra’s
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<ll, 2>> adjList[n];
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adjList[a].push_back({c, b});
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    q.push({0, 0});
    vector<vector<ll>> dist(n, vector<ll>(k, INF));
    dist[0][0] = 0;
    while (!q.empty())
    {
        array<ll, 2> curr = q.top();
        q.pop();
        ll d = curr[0];
        ll u = curr[1];
        if (dist[u][k - 1] < d)
        {
            continue;
        }
        for (array<ll, 2> neighbor : adjList[u])
        {
            ll cost = neighbor[0];
            ll v = neighbor[1];
            if (dist[v][k - 1] > cost + d)
            {
                dist[v][k - 1] = cost + d;
                q.push({dist[v][k - 1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << dist[n - 1][i] << " ";
    }
    cout << endl;
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