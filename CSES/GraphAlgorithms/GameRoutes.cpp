#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void dfs(vector<vector<int>> &adjList, vector<int> &visited, vector<ll> &dp, int curr)
{
    int n = dp.size();
    dp[curr] = curr == (n - 1) ? 1 : 0;
    visited[curr] = 1;
    for (int v : adjList[curr])
    {
        if (!visited[v])
        {
            dfs(adjList, visited, dp, v);
        }
        dp[curr] = (dp[curr] + dp[v]) % mod;
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    ll a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
    }
    vector<int> visited(n, 0);
    vector<ll> dp(n);
    dfs(adjList, visited, dp, 0);
    cout << dp[0] << endl;
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