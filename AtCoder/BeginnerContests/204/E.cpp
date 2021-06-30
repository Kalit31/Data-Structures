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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<ll, 2>> adjList[n];
    vector<ll> c(m);
    vector<ll> d(m);
    ll a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c[i] >> d[i];
        a--;
        b--;
        adjList[a].push_back({b, i});
        adjList[b].push_back({a, i});
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
            int vertex = v[0];
            int edgeInd = v[1];
            ll optimum = sqrt(d[edgeInd]);
            ll timeToReachV = dist[curr[1]] + c[edgeInd] + (d[edgeInd] / (dist[curr[1]] + 1));
            for (ll choice = max(dist[curr[1]], optimum - 10); choice < optimum + 10; choice++)
            {
                timeToReachV = min(timeToReachV, choice + c[edgeInd] + (d[edgeInd] / (choice + 1)));
            }
            if (dist[vertex] > timeToReachV)
            {
                dist[vertex] = timeToReachV;
                q.push({dist[vertex], vertex});
            }
        }
        processed.insert(curr[1]);
    }
    if (dist[n - 1] == LONG_LONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << dist[n - 1] << endl;
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