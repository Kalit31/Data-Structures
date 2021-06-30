#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    int n;
    cin >> n;
    vector<array<ll, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll t1 = a[i][0];
            ll l1 = a[i][1];
            ll r1 = a[i][2];
            ll t2 = a[j][0];
            ll l2 = a[j][1];
            ll r2 = a[j][2];
            if (l1 <= r2 && l2 <= r1)
            {
                if (l1 == r2)
                {
                    if ((t1 == 1 || t1 == 2) && (t2 == 1 || t2 == 3))
                    {
                        ans++;
                    }
                }
                else if (l2 == r1)
                {
                    if ((t1 == 1 || t1 == 3) && (t2 == 1 || t2 == 2))
                    {
                        ans++;
                    }
                }
                else
                {
                    ans++;
                }
            }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}