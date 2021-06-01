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
    int n, k;
    cin >> n >> k;
    vector<array<ll, 2>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    ll canReach = k;
    ll coins = k;
    ll last = 0;
    for (int i = 0; i < n; i++)
    {
        if (canReach >= arr[i][0])
        {
            ll rem = coins - (arr[i][0] - last);
            coins = rem + arr[i][1];
            canReach = arr[i][0] + coins;
            last = arr[i][0];
        }
        else
        {
            cout << canReach << endl;
            return;
        }
    }
    cout << canReach << endl;
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