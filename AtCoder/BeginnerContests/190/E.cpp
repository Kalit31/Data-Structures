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
const int INF = 1e9;
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

const int MAX = 1e5 + 10;
int n, m, k;
vector<vector<ll>> adjList(MAX);
int dp[18][(1 << 18)];
vector<int> c(18);
int dist[MAX][18];

void bfs(int node)
{
    for (int i = 0; i < n; i++)
    {
        dist[i][node] = INF;
    }
    queue<int> q;
    q.push(c[node]);

    //dist from itself is 0
    dist[c[node]][node] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int v : adjList[curr])
        {
            if (dist[v][node] == INF)
            {
                dist[v][node] = dist[curr][node] + 1;
                q.push(v);
            }
        }
    }
}

int build(int last, int mask)
{
    if (mask == ((1 << k) - 1))
        return 0;
    if (dp[last][mask] != -1)
    {
        return dp[last][mask];
    }
    int ans = INF;
    for (int i = 0; i < k; i++)
    {
        if (mask & (1 << i))
            continue;
        ans = min(ans, build(i, mask | (1 << i)) + dist[c[last]][i]);
    }
    dp[last][mask] = ans;
    return ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < k; i++)
    {
        bfs(i);
    }
    for (int i = 0; i < k; i++)
    {
        if (dist[c[0]][i] == INF)
        {
            cout << -1 << endl;
            return;
        }
    }
    int ans = INF;
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, 1 + build(i, 1 << i));
    }
    cout << ans << endl;
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