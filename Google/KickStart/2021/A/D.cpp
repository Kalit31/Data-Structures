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

vector<int> parent;
vector<int> rnk;

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }
    vector<int> r(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int cost = 0;
    int totalWt = 0;
    vector<Edge> edges;
    parent.resize(2 * n);
    rnk.resize(2 * n);
    for (int i = 0; i < 2 * n; i++)
        make_set(i);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                Edge e;
                e.u = i;
                e.v = j + n;
                e.weight = -b[i][j];
                edges.push_back(e);
                totalWt += b[i][j];
            }
        }
    }
    sort(edges.begin(), edges.end());
    for (Edge e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }
    cout << totalWt + cost << endl;
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
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}