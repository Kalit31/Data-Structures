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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = (i % 2 == 0 ? -1 : 1);
    }
    ll x;
    while (q--)
    {
        cin >> x;
        if (mp.find(x) != mp.end())
        {
            cout << 0 << endl;
            continue;
        }
        auto it = upper_bound(a.begin(), a.end(), x);
        if (it == a.begin())
        {
            cout << "POSITIVE" << endl;
            continue;
        }
        --it;
        if (mp[*it] > 0)
        {
            cout << "POSITIVE" << endl;
        }
        else
        {
            cout << "NEGATIVE" << endl;
        }
    }
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}
