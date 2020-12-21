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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    int atRisk = 0;
    int notAtRisk = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= 9 || a[i] >= 80)
        {
            atRisk++;
        }
        else
        {
            notAtRisk++;
        }
    }
    int totalDays = ceil((atRisk * 1.0) / d) + ceil((notAtRisk * 1.0) / d);
    cout << totalDays << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}