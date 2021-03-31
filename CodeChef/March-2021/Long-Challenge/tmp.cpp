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
            cout << "(" << nodes[i].l << "," << nodes[i].r << ")" << endl;
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
                if (curr.l <= y && y <= curr.r)
                {
                    minDist = min(minDist, dist);
                    break;
                }
                for (Node nd : adjList[curr])
                {
                    cout << "HERE" << endl;
                    if (!visited[nd])
                    {
                        q.push(nd);
                    }
                }
                dist--;
            }
        }
    }
    minDist = minDist == INT_MAX ? -1 : minDist;
    cout << minDist << endl;
}
