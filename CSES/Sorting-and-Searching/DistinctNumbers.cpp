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
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    ll dist = 1;
    ll last = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] != last)
        {
            dist++;
            last = s[i];
        }
    }
    cout << dist << endl;
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