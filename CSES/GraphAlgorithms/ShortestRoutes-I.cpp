#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

//Djikstra’s algorithm
//O(ElogV + V)
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
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    vector<ll> dist(n, LONG_LONG_MAX);
    dist[0] = 0;
    q.push({0, 0});
    set<int> processed;
    while (!q.empty())
    {
        array<ll, 2> curr = q.top();
        q.pop();

        if (processed.find(curr[1]) != processed.end())
        {
            continue;
        }
        for (array<ll, 2> v : adjList[curr[1]])
        {
            if (dist[v[1]] > dist[curr[1]] + v[0])
            {
                dist[v[1]] = dist[curr[1]] + v[0];
                q.push({dist[v[1]], v[1]});
            }
        }
        processed.insert(curr[1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
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