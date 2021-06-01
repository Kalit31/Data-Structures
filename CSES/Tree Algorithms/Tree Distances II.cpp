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

const int N = 2e5 + 5;

vector<int> adjList[N];
ll dist[N];
ll subtreeSize[N];
int n;

void dfs(int curr, int parent)
{
    for (int v : adjList[curr])
    {
        if (v != parent)
        {
            dfs(v, curr);
            subtreeSize[curr] += subtreeSize[v];
            dist[curr] += dist[v] + subtreeSize[v];
        }
    }
}

void dfs2(int curr, int parent)
{
    for (int v : adjList[curr])
    {
        if (v != parent)
        {
            dist[v] = dist[curr] - subtreeSize[v] + (n - subtreeSize[v]);
            dfs2(v, curr);
        }
    }
}

void solve()
{
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        dist[i] = 0;
        subtreeSize[i] = 1;
    }
    dfs(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}