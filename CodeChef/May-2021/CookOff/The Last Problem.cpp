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

ll mat[1001][1001];

void pre()
{
    memset(mat, 0, sizeof(mat));
    int add = 1;
    for (int i = 1; i <= 1000; i++)
    {
        mat[i][1] = mat[i - 1][1] + add;
        add++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        int add = i;
        for (int j = 2; j <= 1000; j++)
        {
            mat[i][j] = mat[i][j - 1] + add;
            add++;
        }
    }
}

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = 0;
    for (int i = x1; i <= x2; i++)
    {
        ans += mat[i][y1];
    }
    for (int i = y1 + 1; i <= y2; i++)
    {
        ans += mat[x2][i];
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
    pre();
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}