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
    vector<int> a(n);
    vector<int> b(n);
    int maxA = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    int minB = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        minB = min(minB, b[i]);
    }
    if (minB < maxA)
    {
        cout << 0 << endl;
        return;
    }
    cout << minB - maxA + 1 << endl;
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