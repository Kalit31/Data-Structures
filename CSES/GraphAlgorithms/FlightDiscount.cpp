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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<ll, 2>> adjList[n];
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adjList[a].push_back({c, b});
    }
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> q;

    vector<ll> dist(n, INF);
    dist[0] = 0;

    vector<ll> disc(n, INF);
    disc[0] = 0;

    q.push({0, 0, 0});
    while (!q.empty())
    {
        array<ll, 3> curr = q.top();
        q.pop();
        ll d = curr[0];
        ll u = curr[1];
        ll coupon = curr[2];
        if (coupon == 1)
        {
            if (disc[u] < d)
            {
                continue;
            }
        }
        else
        {
            if (dist[u] < d)
            {
                continue;
            }
        }
        for (array<ll, 2> neighbor : adjList[u])
        {
            ll cost = neighbor[0];
            ll v = neighbor[1];
            if (coupon == 0)
            {
                if (dist[v] > cost + d)
                {
                    dist[v] = cost + d;
                    q.push({dist[v], v, 0});
                }
                if (disc[v] > cost / 2 + d)
                {
                    disc[v] = cost / 2 + d;
                    q.push({disc[v], v, 1});
                }
            }
            else
            {
                if (disc[v] > cost + d)
                {
                    disc[v] = cost + d;
                    q.push({disc[v], v, 1});
                }
            }
        }
    }
    cout << disc[n - 1] << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}