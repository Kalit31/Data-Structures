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
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i + 1];
        arr[i + 1] += arr[i];
    }
    set<array<ll, 2>> s;
    ll ans = LONG_LONG_MIN;
    for (int i = 0; i <= n; i++)
    {
        deb(i);
        if (i >= a)
        {
            s.insert({arr[i - a], i - a});
            cout << "INSERTING: "
                 << "{" << arr[i - a] << "," << i - a << "}" << endl;
        }
        if (s.size())
        {
            ans = max(arr[i] - (*s.begin())[0], ans);
            cout << "CALC: " << arr[i] - (*s.begin())[0] << endl;
            deb(ans);
        }
        if (i >= b)
        {
            s.erase({arr[i - b], i - b});
            cout << "ERASING: "
                 << "{" << arr[i - b] << "," << i - b << "}" << endl;
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