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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll count = 0;
    int aInd = 0;
    int bInd = 0;

    while (aInd < n && bInd < m)
    {
        if (b[bInd] <= a[aInd] + k && b[bInd] >= a[aInd] - k)
        {
            count++;
            aInd++;
            bInd++;
            continue;
        }
        if (b[bInd] < a[aInd] - k)
        {
            bInd++;
            continue;
        }
        if (b[bInd] > a[aInd] + k)
        {
            aInd++;
            continue;
        }
    }
    cout << count << endl;
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