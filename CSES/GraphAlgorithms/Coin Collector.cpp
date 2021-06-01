#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

void dfs1(vector<vector<int>> &adjList, stack<int> &st, vector<bool> &visited, int curr)
{
    visited[curr] = true;
    for (int v : adjList[curr])
    {
        if (!visited[v])
        {
            dfs1(adjList, st, visited, v);
        }
    }
    st.push(curr);
}

void dfs2(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &result, int comp, int curr)
{
    visited[curr] = true;
    result[curr] = comp;
    for (int v : adjList[curr])
    {
        if (!visited[v])
        {
            dfs2(adjList, visited, result, comp, v);
        }
    }
}

ll build(vector<vector<int>> &compGraph, vector<ll> &dp, vector<ll> &scc, int curr)
{
    if (dp[curr] != -1)
    {
        return dp[curr];
    }
    dp[curr] = scc[curr];
    for (int v : compGraph[curr])
    {
        dp[curr] = max(dp[curr], build(compGraph, dp, scc, v) + scc[curr]);
    }
    return dp[curr];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

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
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            dfs1(adjList1, st, vis1, i);
        }
    }

    vector<bool> vis2(n, false);
    vector<int> result(n);
    int comp = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!vis2[curr])
        {
            comp++;
            dfs2(adjList2, vis2, result, comp, curr);
        }
    }

    vector<ll> scc(comp, 0);
    for (int i = 0; i < n; i++)
    {
        scc[result[i] - 1] += (ll)k[i];
    }

    vector<vector<int>> compGraph(comp, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j : adjList1[i])
        {
            if (result[i] == result[j])
            {
                continue;
            }
            compGraph[result[i] - 1].push_back(result[j] - 1);
        }
    }
    vector<ll> dp(comp, -1);
    ll ans = 0;
    for (int i = 0; i < comp; i++)
    {
        ans = max(ans, build(compGraph, dp, scc, i));
    }
    cout << ans << endl;
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