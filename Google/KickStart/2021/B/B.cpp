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
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    vector<int> diff(n);
    diff[0] = 1;
    diff[1] = 2;
    for (int i = 2; i < n; i++)
    {
        if ((a[i] - a[i - 1]) == (a[i - 1] - a[i - 2]))
        {
            diff[i] = diff[i - 1] + 1;
        }
        else
        {
            diff[i] = 2;
        }
    }

    vector<int> diff_rev(n);
    diff_rev[n - 1] = 1;
    diff_rev[n - 2] = 2;
    for (int i = n - 3; i >= 0; i--)
    {
        if ((a[i + 1] - a[i]) == (a[i + 2] - a[i + 1]))
        {
            diff_rev[i] = diff_rev[i + 1] + 1;
        }
        else
        {
            diff_rev[i] = 2;
        }
    }

    //include the leftmost element(a[0]) and as much elements on the right as you can
    int ans = 1 + diff_rev[1];
    //include the rightmost element(a[n-1]) and as much elements on the left as you can
    ans = max(ans, 1 + diff[n - 2]);

    //pick each of the ith element
    for (int i = 1; i < n - 1; i++)
    {
        //if the current element is the leftmost element of the chosen subarray
        ans = max(ans, 1 + diff_rev[i + 1]);
        //if the current element is the rightmost element of the chosen subarray
        ans = max(ans, 1 + diff[i - 1]);

        if ((a[i - 1] + a[i + 1]) % 2 != 0)
        {
            //integral value not possible
            continue;
        }
        int d = (a[i + 1] - a[i - 1]) / 2;
        if (i == 1 || a[i - 1] - a[i - 2] == d)
        {
            ans = max(ans, 2 + diff[i - 1]);
        }
        if (i == n - 2 || a[i + 2] - a[i + 1] == d)
        {
            ans = max(ans, 2 + diff_rev[i + 1]);
        }
        if (i == 1 || i == n - 2)
        {
            continue;
        }
        //if common difference same on both sides, merge subarrays
        if (a[i - 1] - a[i - 2] == d && a[i + 2] - a[i + 1] == d)
        {
            ans = max(ans, 1 + diff[i - 1] + diff_rev[i + 1]);
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}