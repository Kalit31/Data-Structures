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
    vector<vector<int>> adjList1(n, vector<int>());
    vector<vector<int>> adjList2(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList1[u].push_back(v);
        adjList2[v].push_back(u);
    }

    vector<bool> vis1(n, false);
    dfs(adjList1, vis1, 0);

    vector<bool> vis2(n, false);
    dfs(adjList2, vis2, 0);

    for (int i = 1; i < n; i++)
    {
        if (!vis1[i] || !vis2[i])
        {
            cout << "NO" << endl;
            if (!vis1[i])
                cout << 1 << " " << i + 1 << endl;
            else
                cout << i + 1 << " " << 1 << endl;
            return;
        }
    }
    cout << "YES" << endl;
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