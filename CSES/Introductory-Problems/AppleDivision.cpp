#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    ll minDiff = INT_MAX;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll sum1 = 0;
        ll sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum1 += p[i];
            }
            else
            {
                sum2 += p[i];
            }
        }
        minDiff = min(minDiff, abs(sum1 - sum2));
    }
    cout << minDiff << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}