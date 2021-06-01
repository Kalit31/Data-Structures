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
// not so neat code, but it works

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    int farthestNodeFrom0 = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int v : adjList[curr])
        {
            if (dist[v] == INT_MAX)
            {
                dist[v] = dist[curr] + 1;
                q.push(v);
                if (dist[farthestNodeFrom0] < dist[v])
                {
                    farthestNodeFrom0 = v;
                }
            }
        }
    }
    vector<int> dist2(n, INT_MAX);
    int farthestNode2 = farthestNodeFrom0;
    dist2[farthestNodeFrom0] = 0;
    q.push(farthestNodeFrom0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int v : adjList[curr])
        {
            if (dist2[v] == INT_MAX)
            {
                dist2[v] = dist2[curr] + 1;
                q.push(v);
                if (dist2[farthestNode2] < dist2[v])
                {
                    farthestNode2 = v;
                }
            }
        }
    }
    vector<int> dist3(n, INT_MAX);
    dist3[farthestNode2] = 0;
    q.push(farthestNode2);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int v : adjList[curr])
        {
            if (dist3[v] == INT_MAX)
            {
                dist3[v] = dist3[curr] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << max(dist2[i], dist3[i]) << " ";
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