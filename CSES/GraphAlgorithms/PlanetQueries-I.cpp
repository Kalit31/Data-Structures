#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i]--;
    }
    vector<vector<int>> parent(n, vector<int>(30));

    for (int i = 0; i < n; i++)
    {
        parent[i][0] = t[i];
    }
    for (int k = 1; k < 30; k++)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        x--;
        for (int i = 0; i < 30; i++)
        {
            if (k & (1 << i))
            {
                x = parent[x][i];
            }
        }
        cout << x + 1 << endl;
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}