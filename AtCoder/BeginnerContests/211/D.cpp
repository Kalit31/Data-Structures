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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<ll> dist(n, INT_MAX);
    dist[0] = 0;
    vector<ll> paths(n, 0);
    paths[0] = 1;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adjList[u])
        {
            if (dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
                paths[v] = paths[u];
                q.push(v);
            }
            else if (dist[u] + 1 == dist[v])
            {
                paths[v] = (paths[v] + paths[u]) % mod;
            }
        }
    }
    cout << paths[n - 1] << endl;
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