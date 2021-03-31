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
    ll n, m, k;
    cin >> n >> m >> k;
    if (n > m)
        swap(n, m);
    ll ans = 0;
    for (int row = 1; row <= n; row++)
    {
        if (row % 2)
        {
            ans = ans ^ (row + 1 + k);
        }
    }
    ll curr = m + n;
    ll col = 1;
    for (; col < m; col++)
    {
        int t = min(n, col);
        if (t % 2)
        {
            ans = ans ^ (curr + k);
        }
        curr--;
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}