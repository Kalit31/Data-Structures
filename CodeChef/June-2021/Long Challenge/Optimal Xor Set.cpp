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
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    ll fXor = 0;
    for (ll mask = 1; mask < (1ll << n); mask++)
    {
        ll setBits = __builtin_popcountll(mask);
        if (setBits == k)
        {
            ll currXor = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    currXor = currXor ^ (i + 1);
                }
            }
            if (currXor >= fXor)
            {
                ans.clear();
                for (int i = 0; i < n; i++)
                {
                    if (mask & (1 << i))
                    {
                        ans.push_back(i + 1);
                    }
                }
                fXor = currXor;
            }
        }
    }
    for (ll x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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