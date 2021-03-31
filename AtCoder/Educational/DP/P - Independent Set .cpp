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

array<ll, 2> dfs(vector<vector<int>> &adjList, int curr, int parent)
{
    ll waysToColorWhite = 1;
    ll waysToColorBlack = 1;

    for (int v : adjList[curr])
    {
        if (v == parent)
            continue;
        //{black,white}
        array<ll, 2> a = dfs(adjList, v, curr);
        waysToColorBlack = (waysToColorBlack * a[1]) % mod;
        waysToColorWhite = (waysToColorWhite * ((a[0] + a[1]) % mod)) % mod;
    }
    return {waysToColorBlack, waysToColorWhite};
}

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
    array<ll, 2> ans = dfs(adjList, 0, -1);
    cout << (ans[0] + ans[1]) % mod << endl;
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