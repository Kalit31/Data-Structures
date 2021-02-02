#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

/*set<ll> s;
    for (ll i = 1; i < pow(2, n); i++)
    {
        ll val = 0;
        ll mult = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & mult)
            {
                val += x[j];
            }
            mult = mult * 2;
        }
        s.insert(val);
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;*/

const int mxSum = 1e5;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(mxSum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= mxSum; j++)
        {
            //do not take the ith coin
            dp[i][j] = dp[i - 1][j];
            //take the ith coin
            if (j - x[i - 1] >= 0)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - x[i - 1]];
            }
        }
    }
    vector<int> sums;
    for (int i = 1; i <= mxSum; i++)
    {
        if (dp[n][i])
        {
            sums.push_back(i);
        }
    }
    cout << sums.size() << endl;
    for (int s : sums)
    {
        cout << s << " ";
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}