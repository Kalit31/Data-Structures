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

const int N = 20;

ll dp[1 << N];
vector<array<int, 2>> arr[N];
int n, m;

ll build(int mask)
{
    if (mask == 0)
    {
        return 1;
    }
    if (dp[mask] != -1)
    {
        return dp[mask];
    }
    int currBits = __builtin_popcountll(mask);
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            a[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    for (auto it : arr[currBits])
    {
        if (a[it[0]] > it[1])
        {
            return dp[mask] = 0;
        }
    }
    ll ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            ways += build(mask ^ (1 << i));
        }
    }
    return dp[mask] = ways;
}

// out of the first 'x' elements, at most 'z' elements should be <= 'y'
void solve()
{
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        arr[x].push_back({y, z});
    }
    memset(dp, -1, sizeof(dp));
    cout << build((1 << n) - 1) << endl;
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