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

int dfs(vector<int> &parent, vector<int> &depth, int curr)
{
    if (depth[curr] != -1)
    {
        return depth[curr];
    }
    depth[curr] = 1 + dfs(parent, depth, parent[curr]);
    return depth[curr];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> parent(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }

    vector<vector<int>> ancestor(n, vector<int>(20));
    vector<int> depth(n, -1);
    depth[0] = 0;

    for (int i = 0; i < n; i++)
    {
        ancestor[i][0] = parent[i];
        dfs(parent, depth, i);
    }

    for (int h = 1; h < 20; h++)
    {
        for (int i = 0; i < n; i++)
        {
            ancestor[i][h] = ancestor[ancestor[i][h - 1]][h - 1];
        }
    }
    int x, k;
    while (q--)
    {
        cin >> x >> k;
        x--;
        if (depth[x] < k)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < 20; i++)
            {
                if (k & (1 << i))
                {
                    x = ancestor[x][i];
                }
            }
            cout << x + 1 << endl;
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