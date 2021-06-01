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
int dist[N];
int ancestor[N][20];
int cnt[N];

void dfs(int curr, int parent)
{
    for (int v : adjList[curr])
    {
        if (v != parent)
        {
            dist[v] = dist[curr] + 1;
            ancestor[v][0] = curr;
            for (int i = 1; i < 20; i++)
            {
                ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
            }
            dfs(v, curr);
        }
    }
}

int find_lca(int a, int b)
{
    if (dist[a] < dist[b])
    {
        swap(a, b);
    }
    int k = dist[a] - dist[b];
    //make nodes art same depth
    for (int i = 0; i < 20; i++)
    {
        if (k & (1 << i))
        {
            a = ancestor[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (ancestor[a][i] != ancestor[b][i])
        {
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }
    return ancestor[a][0];
}

int dfs2(int curr, int parent)
{
    int ans = 0;
    for (int v : adjList[curr])
    {
        if (v != parent)
        {
            ans += dfs2(v, curr);
        }
    }
    cnt[curr] += ans;
    return cnt[curr];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dist[0] = 0;
    dfs(0, -1);

    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
    }

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        a--;
        b--;
        int lca = find_lca(a, b);
        int parent = ancestor[lca][0];
        cnt[a]++;
        cnt[b]++;
        cnt[lca]--;
        if (parent != lca)
        {
            cnt[parent]--;
        }
    }

    dfs2(0, -1);

    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] << " ";
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