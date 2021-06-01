#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int curr)
{
    visited[curr] = true;
    for (int v : adjList[curr])
    {
        if (!visited[v])
        {
            dfs(adjList, visited, v);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n, vector<int>());
    vector<int> degree(n, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (degree[i] != 0)
        {
            dfs(adjList, visited, i);
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && degree[i] != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    //TODO
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