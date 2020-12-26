#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void dfs(vector<vector<int>> &adjList, vector<int> &visited, vector<int> &parent, vector<int> &ans, int curr)
{
    visited[curr] = 1;
    for (int v : adjList[curr])
    {
        if (v == parent[curr])
        {
            continue;
        }
        if (visited[v] == 0)
        {
            parent[v] = curr;
            visited[v] = 1;
            dfs(adjList, visited, parent, ans, v);
        }
        else
        {
            ans.push_back(v);
            while (curr != v)
            {
                ans.push_back(curr);
                curr = parent[curr];
            }
            ans.push_back(v);
            cout << ans.size() << endl;
            for (int a : ans)
            {
                cout << a + 1 << " ";
            }
            cout << endl;
            exit(0);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        from--;
        to--;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    vector<int> path;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(adjList, visited, parent, path, i);
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}