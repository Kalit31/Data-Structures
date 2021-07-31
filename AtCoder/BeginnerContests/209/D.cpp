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

void dfs(vector<vector<int>> &adjList, int curr, vector<int> &dist, int parent, int currDist)
{
    dist[curr] = currDist;
    for (int v : adjList[curr])
    {
        if (v != parent)
        {
            dfs(adjList, v, dist, curr, currDist + 1);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adjList(n);
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> dist(n, 0);
    dfs(adjList, 0, dist, -1, 0);
    int c, d;
    while (q--)
    {
        cin >> c >> d;
        c--;
        d--;
        int totDist = dist[c] + dist[d];
        if (totDist % 2 == 1)
        {
            cout << "Road" << endl;
        }
        else
        {
            cout << "Town" << endl;
        }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}