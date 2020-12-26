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

ll sol(vector<ll> &A, int l, int r, vector<vector<ll>> &dp)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
    {
        return A[l];
    }
    if (l >= A.size())
    {
        return 0;
    }
    if (r < 0)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    ll left = A[l] + min(sol(A, l + 2, r, dp), sol(A, l + 1, r - 1, dp));
    ll right = A[r] + min(sol(A, l, r - 2, dp), sol(A, l + 1, r - 1, dp));
    dp[l][r] = max(left, right);
    return dp[l][r];
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << sol(x, 0, n - 1, dp) << endl;
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