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

vector<array<ll, 2>> arr;
vector<bool> visited;
vector<int> indegree;
ll cnt = 0;

void alltopologicalSortUtil(vector<int> &res, vector<vector<int>> &adjList)
{
    int n = visited.size();
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0 && !visited[i])
        {
            for (int v : adjList[i])
                indegree[v]--;

            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, adjList);

            visited[i] = false;
            res.pop_back();
            for (int v : adjList[i])
                indegree[v]++;
        }
    }
    if (res.size() == n)
    {
        cnt = (cnt + 1) % mod;
        // for (int i = 0; i < res.size(); i++)
        //     cout << res[i] << " ";
        // cout << endl;
    }
}

void buildDirectedGraph(vector<vector<int>> &dir, vector<vector<int>> &adjList, int currNode)
{
    visited[currNode] = true;
    for (int v : adjList[currNode])
    {
        if (!visited[v])
        {
            dir[v].push_back(currNode);
            indegree[currNode]++;
            buildDirectedGraph(dir, adjList, v);
        }
    }
}

void build(vector<vector<int>> &adjList, int u)
{
    int n = adjList.size();
    vector<vector<int>> dirList(n);
    visited.clear();
    indegree.clear();
    visited.resize(n, false);
    indegree.resize(n, 0);
    buildDirectedGraph(dirList, adjList, u);
    // cout << "ADJLIST: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "->";
    //     for (int v : adjList[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "DIR GRAPH: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "->";
    //     for (int v : dirList[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << indegree[i] << " ";
    // }
    // cout << endl;
    visited.clear();
    visited.resize(n, false);
    vector<int> res;
    cnt = 0;
    alltopologicalSortUtil(res, dirList);
    arr.push_back({cnt, u});
}

void solve()
{
    arr.clear();
    visited.clear();
    indegree.clear();
    int n, k;
    cin >> n >> k;
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
    for (int i = 0; i < n; i++)
    {
        build(adjList, i);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    cout << arr[k - 1][1] + 1 << " " << arr[k - 1][0] << endl;
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