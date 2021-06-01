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

int dp[N][2];

int build(vector<vector<int>> &adjList, int curr, int chooseEdge, int parent)
{
    if (dp[curr][chooseEdge] != -1)
    {
        return dp[curr][chooseEdge];
    }

    if (chooseEdge)
    {
        // choose one of the edges from curr;
        dp[curr][chooseEdge] = 0;
        map<int, int> mp;
        int total = 0;
        for (int i = 0; i < adjList[curr].size(); i++)
        {
            if (adjList[curr][i] != parent)
            {
                int curr_ans = max(build(adjList, adjList[curr][i], 0, curr), build(adjList, adjList[curr][i], 1, curr));
                total += curr_ans;
                mp[adjList[curr][i]] = curr_ans;
            }
        }
        int final_ans = 0;
        for (int i = 0; i < adjList[curr].size(); i++)
        {
            //chose an edge from curr to adjList[curr][i]
            if (adjList[curr][i] != parent)
                final_ans = max(final_ans, 1 + total - mp[adjList[curr][i]] + build(adjList, adjList[curr][i], 0, curr));
        }
        dp[curr][chooseEdge] += final_ans;
    }
    else
    {
        // do not choose any edge from curr
        dp[curr][chooseEdge] = 0;
        for (int v : adjList[curr])
        {
            if (v != parent)
                dp[curr][chooseEdge] += max(build(adjList, v, 0, curr), build(adjList, v, 1, curr));
        }
    }
    return dp[curr][chooseEdge];
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
    memset(dp, -1, sizeof(dp));
    cout << max(build(adjList, 0, 0, -1), build(adjList, 0, 1, -1)) << endl;
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