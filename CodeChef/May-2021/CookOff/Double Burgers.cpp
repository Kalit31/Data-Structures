#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

void solve()
{
    ll x, y;
    cin >> x >> y;

    if (y % x != 0)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = y / x;
    for (ll m = 1; m <= 64; m++)
    {
        ll curr = ans + m;
        if (__builtin_popcountll(curr) == m)
        {
            int res = m - 1;
            int i = 0;
            while (curr != 0)
            {
                if (curr & 1)
                {
                    res += i;
                }
                i++;
                curr /= 2;
            }
            cout << res << endl;
            return;
        }
    }
    cout << -1 << endl;
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