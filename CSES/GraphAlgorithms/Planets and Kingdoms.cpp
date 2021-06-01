#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

//Kosaraju Algorithm

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
    cout << comp << endl;
    for (int x : result)
    {
        cout << x << " ";
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