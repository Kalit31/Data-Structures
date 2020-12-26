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

    int n;
    cin >> n;
    int x;
    vector<ll> dp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int ind = lower_bound(dp.begin(), dp.end(), x) - dp.begin();

        if (ind < dp.size())
        {
            dp[ind] = x;
        }
        else
        {
            dp.push_back(x);
        }
    }
    cout << dp.size() << endl;

    /* O(N^2) soln
    vector<ll> dp(n, 1);
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < i; j++)
        {
            if (x[i] > x[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    */
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