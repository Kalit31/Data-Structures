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

const int R = 505;
const int C = 505;

int dp[R][C];

int build(int x, int y, vector<vector<int>> &a, vector<vector<int>> &b, int r, int c)
{
    deb(x);
    deb(y);
    if (x < 0 || y < 0 || x >= r || y >= c)
    {
        return INT_MAX;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    int ans = INT_MAX;

    //come from left
    //(x,y-1) -> (x,y) with cost a[x][y-1]
    if (y > 0)
    {
        ans = min(ans, build(x, y - 1, a, b, r, c) + a[x][y - 1]);
    }
    //come from right
    //(x,y+1) -> (x,y) with cost a[x][y]
    if (y < (c - 1))
    {
        ans = min(ans, build(x, y + 1, a, b, r, c) + a[x][y]);
    }
    // //come from up
    // //(x-1,y) -> (x,y) with cost b[x-1][y]
    // if (x > 0)
    // {
    //     ans = min(ans, build(x - 1, y, a, b, r, c) + b[x - 1][y]);
    // }

    // //come from down
    // for (int row = x + 1; row < r; row++)
    // {
    //     ans = min(ans, build(row, y, a, b, r, c) + (1 + row - x));
    // }

    return dp[x][y] = ans;
}
void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c - 1));
    vector<vector<int>> b(r - 1, vector<int>(c));

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < r; i++)

        cout << build(r - 1, c - 1, a, b, r, c) << endl;
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