#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> dp(n);
    deque<int> q;
    for (int i = 0; i <= k; i++)
    {
        dp[i] = h[i];
        while (!q.empty() && dp[q.back()] > dp[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (int i = k + 1; i < n; i++)
    {
        while (q.front() < (i - k - 1))
        {
            q.pop_front();
        }
        dp[i] = h[i] + dp[q.front()];
        while (!q.empty() && dp[q.back()] > dp[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    int ans = INT_MAX;

    for (int i = n - 1; i >= (n - k - 1); i--)
    {
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}