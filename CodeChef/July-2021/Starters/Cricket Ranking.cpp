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
    int r1, w1, c1;
    int r2, w2, c2;
    cin >> r1 >> w1 >> c1;
    cin >> r2 >> w2 >> c2;
    int pl1 = 0;
    int pl2 = 0;
    pl1 += (r1 > r2);
    pl2 += (r1 < r2);

    pl1 += (w1 > w2);
    pl2 += (w1 < w2);

    pl1 += (c1 > c2);
    pl2 += (c1 < c2);

    if (pl1 > pl2)
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "B" << endl;
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