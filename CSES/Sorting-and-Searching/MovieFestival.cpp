#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 1;
    int last = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first >= last)
        {
            ans++;
            last = arr[i].second;
        }
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