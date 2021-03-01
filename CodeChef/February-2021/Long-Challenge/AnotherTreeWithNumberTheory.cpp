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

ll ignored = 0;
void buildX(vector<vector<int>> &adjList, vector<ll> &num, int currNode, ll val)
{
    ll children = adjList[currNode].size();
    if (children == 0)
    {
        return;
    }
    //deb(children);
    ll currVal = num[currNode];
    if (currVal < INT_MAX && currVal != 0)
    {
        if (val % currVal == 0)
        {
            return;
        }
    }
    if (val % children == 0)
    {
        for (int child : adjList[currNode])
        {
            buildX(adjList, num, child, val / children);
        }
    }
    else
    {
        //   deb(currNode);
        ignored += val;
    }
}

void build(vector<vector<int>> &adjList, int currNode, ll val)
{
    ll children = adjList[currNode].size();
    if (children == 0)
    {
        return;
    }
    //deb(children);
    // ll currVal = num[currNode];
    // if (currVal < INT_MAX && currVal != 0)
    // {
    //     if (val % currVal == 0)
    //     {
    //         return;
    //     }
    // }
    if (val % children == 0)
    {
        for (int child : adjList[currNode])
        {
            build(adjList, child, val / children);
        }
    }
    else
    {
        //   deb(currNode);
        ignored += val;
    }
}

ll pre(vector<vector<int>> &adjList, vector<ll> &num, int currNode)
{
    ll children = adjList[currNode].size();
    if (children == 0)
    {
        num[currNode] = 1;
        return 1;
    }
    ll ans = children;
    for (int child : adjList[currNode])
    {
        ll val = pre(adjList, num, child);
        if (ans * val >= INT_MAX)
        {
            ans = INT_MAX;
        }
        else
        {
            ans = ans * val;
        }
    }
    num[currNode] = ans;
    return ans;
}

void fixTree(vector<vector<int>> &adjList, int node, int parent = -1)
{
    int children = adjList[node].size();
    if (children == 0)
    {
        return;
    }
    else if (children == 1)
    {
        int child = adjList[node][0];
        if (parent != -1)
        {
            adjList[parent].clear();
            adjList[parent].push_back(child);
            fixTree(adjList, child, parent);
        }
        else
        {
            fixTree(adjList, child, node);
        }
    }
    else
    {
        for (int child : adjList[node])
        {
            fixTree(adjList, child, node);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    int p;
    for (int i = 1; i < n; i++)
    {
        cin >> p;
        p--;
        adjList[p].push_back(i);
    }
    fixTree(adjList, 0);
    //   vector<ll> num(n);
    //   pre(adjList, num, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int v, w;
        ignored = 0;
        cin >> v >> w;
        v--;
        //      build(adjList, num, v, w);
        build(adjList, v, w);

        cout << ignored << endl;
    }
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}