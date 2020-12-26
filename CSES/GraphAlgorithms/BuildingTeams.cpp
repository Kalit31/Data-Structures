#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool isBipartite(vector<vector<int>> &adjList, int node, vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int e : adjList[curr])
        {
            if (color[e] == color[curr])
            {
                return false;
            }
            if (color[e] == -1)
            {
                color[e] = 1 - color[curr];
                q.push(e);
            }
        }
    }
    return true;
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
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(adjList, i, color))
            {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}