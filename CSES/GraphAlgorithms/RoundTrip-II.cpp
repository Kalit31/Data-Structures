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

//Find cycle in directed graph
void dfs(vector<vector<int>> &adjList, vector<int> &visited, vector<int> &parent, int curr)
{
    if (visited[curr] == 1)
    {
        //cycle present
        vector<int> ans;
        ans.push_back(curr);
        int x = curr;
        do
        {
            x = parent[x];
            ans.push_back(x);
        } while (curr != x);
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for (int a : ans)
        {
            cout << a + 1 << " ";
        }
        cout << endl;
        exit(0);
    }
    if (visited[curr] == 2)
    {
        return;
    }
    visited[curr] = 1;
    for (int v : adjList[curr])
    {
        parent[v] = curr;
        dfs(adjList, visited, parent, v);
    }
    visited[curr] = 2;
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
    }
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(adjList, visited, parent, i);
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}