#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

const int mxSum = 1e5;

void solve()
{
    ll n;
    cin >> n;
    ll totSum = n * (n + 1);
    if (totSum % 4 != 0)
    {
        cout << 0 << endl;
        return;
    }
    totSum /= 4;
    //deb(totSum);
    vector<vector<ll>> dp(n, vector<ll>(totSum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= (n - 1); i++)
    {
        for (int j = 0; j <= totSum; j++)
        {
            // do not take i
            dp[i][j] = dp[i - 1][j];
            //take i
            if (j - i >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
            }
        }
    }
    cout << dp[n - 1][totSum] << endl;
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