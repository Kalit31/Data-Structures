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

//1 0 1 2 0
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> c(n, INT_MAX);
    c[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            c[i] = 0;
        }
    }
    //traverse from left to right
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            last = i;
        }
        if (last != -1)
        {
            c[i] = min(c[i], i - last);
        }
    }

    //traverse from right to left
    last = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 2)
        {
            last = i;
        }
        if (last != n)
        {
            c[i] = min(c[i], last - i);
        }
    }
    for (int x : b)
    {
        cout << (c[x - 1] == INT_MAX ? -1 : c[x - 1]) << " ";
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