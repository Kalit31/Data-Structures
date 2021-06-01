#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

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

const int N = 2e5 + 5;
vector<array<ll, 2>> adjList[N];
ll dist[N];

void dfs(int currNode, int parent, ll currDist)
{
    dist[currNode] = currDist;
    for (array<ll, 2> v : adjList[currNode])
    {
        if (v[0] != parent)
        {
            dfs(v[0], currNode, currDist ^ v[1]);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    ll u, v, w;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    dfs(0, -1, 0ll);
    ll ans = 0;
    for (ll i = 0; i < 60; i++)
    {
        ll cntOnes = 0;
        ll cntZeros = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[j] & (1ll << i))
            {
                cntOnes++;
            }
            else
            {
                cntZeros++;
            }
        }
        ll totCnt = (cntOnes * cntZeros) % mod;
        ans = (ans + ((1ll << i) % mod * totCnt) % mod);
    }
    ans = ans % mod;
    //ans = (ans % mod * my_pow(2, mod - 2, mod) % mod) % mod;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}