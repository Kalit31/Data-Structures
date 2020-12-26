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

bool comp(const array<ll, 3> &a, const array<ll, 3> &b)
{
    return a[1] < b[1];
}

void solve()
{
    ll n;
    cin >> n;
    vector<array<ll, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), comp);
    /*for (int i = 0; i < n; i++)
    {
        cout << a[i][0] << "-" << a[i][1] << ":" << a[i][2] << endl;
    }*/
    //Include the first project;
    set<array<ll, 2>> s;
    s.insert({0, 0});
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({a[i][0]});
        --it;
        ans = max(ans, a[i][2] + (*it)[1]);
        s.insert({a[i][1], ans});
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