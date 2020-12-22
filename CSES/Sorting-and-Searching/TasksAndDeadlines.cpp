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
    ll n;
    cin >> n;
    vector<array<int, 2>> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i][0] >> tasks[i][1];
    }
    sort(tasks.begin(), tasks.end());
    ll ans = 0;
    ll time = 0;
    for (int i = 0; i < n; i++)
    {
        time += tasks[i][0];
        ans += tasks[i][1] - time;
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}