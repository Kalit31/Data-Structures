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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<int> s;
    multiset<int> ms;

    ll i = 0;
    ll j = 0;
    ll ans = 0;
    while (j < n)
    {
        s.insert(a[j]);
        ms.insert(a[j]);
        while (i <= j && (int)s.size() > k)
        {
            auto it = ms.find(a[i]);
            ms.erase(it);
            if (ms.find(a[i]) == ms.end())
            {
                s.erase(a[i]);
            }
            i++;
        }
        ans += (j - i + 1);
        j++;
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