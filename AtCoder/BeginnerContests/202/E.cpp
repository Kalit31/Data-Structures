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

const int N = 2e5 + 5;

vector<int> adjList[N];
vector<int> depth[N];
int start[N];
int en[N];
int timer = 0;

void dfs(int curr, int d)
{
    start[curr] = timer++;
    depth[d].push_back(start[curr]);

    for (int v : adjList[curr])
    {
        dfs(v, d + 1);
    }
    en[curr] = timer++;
}

void solve()
{
    int n;
    cin >> n;
    int p;
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        adjList[p].push_back(i);
    }
    dfs(1, 0);

    int q;
    cin >> q;
    int u, d;
    while (q--)
    {
        cin >> u >> d;
        int s = start[u];
        int e = en[u];
        vector<int> nodes = depth[d];
        int ans = lower_bound(depth[d].begin(), depth[d].end(), e) - lower_bound(depth[d].begin(), depth[d].end(), s);
        cout << ans << endl;
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