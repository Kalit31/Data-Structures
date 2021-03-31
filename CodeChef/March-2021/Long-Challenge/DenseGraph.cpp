#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()

void solveBrute()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<vector<int>> adjList(n);
    int a, b, c, d;
    while (m--)
    {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        for (int i = a; i <= b; i++)
        {
            for (int j = c; j <= d; j++)
            {
                adjList[i].push_back(j);
            }
        }
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int ans = -1;
    int dist = 0;
    int sz = q.size();
    while (!q.empty())
    {
        if (sz == 0)
        {
            sz = q.size();
            dist++;
        }
        int curr = q.front();
        q.pop();
        if (curr == y)
        {
            ans = dist;
            break;
        }
        for (int v : adjList[curr])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
        sz--;
    }
    cout << ans << endl;
}

struct Node
{
    int l;
    int r;

    bool operator<(const Node &ob) const
    {
        return l < ob.l || (l == ob.l && r < ob.r);
    }
};

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<Node> nodes;
    map<Node, vector<Node>> adjList;
    int a, b, c, d;
    while (m--)
    {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        Node from, to;
        from.l = a;
        from.r = b;
        to.l = c;
        to.r = d;
        adjList[from].push_back(to);
        nodes.push_back(from);
        nodes.push_back(to);
    }
    int minDist = INT_MAX;
    for (int i = 0; i < nodes.size(); i++)
    {
        map<Node, bool> visited;
        int dist = 0;
        if (nodes[i].l <= x && x <= nodes[i].r)
        {
            //cout << "(" << nodes[i].l << "," << nodes[i].r << ")" << endl;
            if (nodes[i].l <= y && y <= nodes[i].r)
            {
                minDist = min(minDist, 0);
                break;
            }
            else
            {
                queue<Node> q;
                q.push(nodes[i]);
                visited[nodes[i]] = true;
                int sz = q.size();
                while (!q.empty())
                {
                    if (sz == 0)
                    {
                        sz = q.size();
                        dist++;
                    }
                    Node curr = q.front();
                    q.pop();

                    for (Node nd : adjList[curr])
                    {
                        if (!visited[nd])
                        {
                            if (nd.l <= y && y <= nd.r)
                            {
                                minDist = min(minDist, dist + 1);
                            }
                            q.push(nd);
                        }
                    }
                    dist--;
                }
            }
        }
    }
    minDist = minDist == INT_MAX ? -1 : minDist;
    cout << minDist << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}