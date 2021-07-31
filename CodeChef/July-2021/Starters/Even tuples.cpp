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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> even(n, 0);
    even[0] = a[0] % 2 == 0;
    for (int i = 1; i < n; i++)
    {
        even[i] += even[i - 1] + (a[i] % 2 == 0);
    }
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        ll evenCnt = even[r] - (l > 0 ? even[l - 1] : 0);
        ll oddCnt = r - l + 1 - evenCnt;
        ll ans = 0;

        ans += max(0ll, (evenCnt * (evenCnt - 1) * (evenCnt - 2)) / 6);
        ans += max(0ll, (evenCnt * (oddCnt) * (oddCnt - 1)) / 2);

        cout << ans << endl;
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}