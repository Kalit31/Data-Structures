#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

ll dfs(vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &level, vector<int> &color, int currNode)
{
    ll currAns = 1;
    visited[currNode] = true;

    for (int v : adjList[currNode])
    {
        if (level[v] != 0 && level[v] != level[currNode] + 1)
        {
            if (color[v] == color[currNode])
            {
                currAns = 0;
            }
            continue;
        }
        level[v] = level[currNode] + 1;
        ll ans = 0;
        for (int currColor = 1; currColor <= 3; currColor++)
        {
            if (currColor == color[currNode])
            {
                continue;
            }
            color[v] = currColor;
            ans += dfs(adjList, visited, level, color, v);
            color[v] = 0;
        }
        currAns *= ans;
    }
    return currAns;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> color(n, 0);
    vector<int> level(n, 0);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        color[i] = 1;
        level[i] = 1;
        ans *= (3 * dfs(adjList, visited, level, color, i));
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}