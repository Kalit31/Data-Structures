#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

int dp[1005][100005];

void solve()
{
    memset(dp, 0, sizeof(dp));
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j >= h[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            }
        }
    }
    cout << dp[n][x] << endl;
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