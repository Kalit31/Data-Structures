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

int dfs(vector<vector<int>> &adjList, int curr, vector<int> &subEmp)
{
    subEmp[curr] = 0;
    for (int v : adjList[curr])
    {
        subEmp[curr] += dfs(adjList, v, subEmp);
    }
    return 1 + subEmp[curr];
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    int u;
    for (int i = 1; i < n; i++)
    {
        cin >> u;
        u--;
        adjList[u].push_back(i);
    }
    vector<int> subEmployess(n, 0);
    dfs(adjList, 0, subEmployess);
    for (int x : subEmployess)
    {
        cout << x << " ";
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}