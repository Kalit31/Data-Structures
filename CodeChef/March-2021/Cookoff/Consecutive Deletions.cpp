#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt1++;
    }
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    int minSubSum = INT_MAX;
    for (int i = 0; i <= n - k; i++)
    {
        int curr = pref[i + k] - pref[i];
        minSubSum = min(minSubSum, curr);
    }
    int ans = ((ll)minSubSum * (ll)(minSubSum + 1)) / 2 + (cnt1 - minSubSum);
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