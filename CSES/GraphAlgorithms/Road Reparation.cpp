#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

//Kruskal's Algorithm
struct node
{
    int parent;
    int rank;
};

struct Edge
{
    int src;
    int dst;
    ll wt;
};

vector<node> dsuf;
vector<Edge> mst;

//FIND operation
int find(int v)
{
    if (dsuf[v].parent == v)
        return v;
    return dsuf[v].parent = find(dsuf[v].parent); //Path Compression
}

void union_op(int fromP, int toP)
{
    if (dsuf[fromP].rank > dsuf[toP].rank) //fromP has higher rank
        dsuf[toP].parent = fromP;
    else if (dsuf[fromP].rank < dsuf[toP].rank) //toP has higher rank
        dsuf[fromP].parent = toP;
    else
    {
        //Both have same rank and so anyone can be made as parent
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1; //Increase rank of parent
    }
}

bool comparator(Edge a, Edge b)
{
    return a.wt < b.wt;
}

int Kruskals(vector<Edge> &edge_List, int V, int E)
{
    sort(edge_List.begin(), edge_List.end(), comparator);

    int i = 0, j = 0;
    while (i < V - 1 && j < E)
    {
        int fromP = find(edge_List[j].src); //FIND absolute parent of subset
        int toP = find(edge_List[j].dst);

        if (fromP == toP)
        {
            ++j;
            continue;
        }

        //UNION operation
        union_op(fromP, toP); //UNION of 2 sets
        mst.push_back(edge_List[j]);
        ++i;
    }
    return i;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    dsuf.resize(n);
    for (int i = 0; i < n; i++)
    {
        dsuf[i].parent = i;
        dsuf[i].rank = 0;
    }

    vector<Edge> edges;
    Edge e;
    for (int i = 0; i < m; i++)
    {
        int src, dst, c;
        cin >> src >> dst >> c;
        src--;
        dst--;
        e.src = src;
        e.dst = dst;
        e.wt = c;
        edges.push_back(e);
    }
    int cnt = Kruskals(edges, n, m);

    if (cnt != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll minCost = 0;
    for (Edge e : mst)
    {
        minCost += e.wt;
    }
    cout << minCost << endl;
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