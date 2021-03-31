#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

void dfs(vector<vector<int>> &adjList, vector<int> &indegree, vector<int> &dist, vector<bool> &visited, int curr)
{
    visited[curr] = true;
    for (int v : adjList[curr])
    {
        dist[v] = max(dist[v], dist[curr] + 1);
        indegree[v]--;
        if (indegree[v] == 0 && !visited[v])
        {
            dfs(adjList, indegree, dist, visited, v);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        indegree[v]++;
    }
    vector<bool> visited(n, false);
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && indegree[i] == 0)
        {
            dfs(adjList, indegree, dist, visited, i);
        }
    }
    cout << *max_element(dist.begin(), dist.end()) << endl;
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