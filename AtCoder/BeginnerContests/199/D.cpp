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

const int N = 21;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> color;
vector<int> nodesInComp;
ll ways = 0;

void dfs(int curr)
{
    visited[curr] = true;
    nodesInComp.push_back(curr);
    for (int v : adjList[curr])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

void dfs2(int i)
{
    if (i == nodesInComp.size())
    {
        ways++;
        return;
    }
    int currNode = nodesInComp[i];
    for (int col = 0; col < 3; col++)
    {
        color[currNode] = col;
        bool ok = true;
        for (int v : adjList[currNode])
        {
            if (color[v] == col)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            continue;
        }
        dfs2(i + 1);
    }
    color[currNode] = -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    adjList.resize(n, vector<int>());

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    visited.resize(n, false);
    color.resize(n, -1);
    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        ans = ans * 3;
        nodesInComp.clear();
        dfs(i);
        color[nodesInComp[0]] = 0;
        ways = 0;
        dfs2(1);
        ans = ans * ways;
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