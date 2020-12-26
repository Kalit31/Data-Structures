#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int h = 1; h <= a; h++)
    {
        for (int w = 1; w <= b; w++)
        {
            if (h == w)
            {
                dp[h][w] = 0;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i < h; i++)
                {
                    ans = min(ans, 1 + dp[h - i][w] + dp[i][w]);
                }
                for (int i = 1; i < w; i++)
                {
                    ans = min(ans, 1 + dp[h][w - i] + dp[h][i]);
                }
                dp[h][w] = ans;
            }
        }
    }
    cout << dp[a][b] << endl;
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