#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
ll ans = 0;

bool check(vector<vector<int>> &mtx, int row, int col)
{
    //check column
    for (int i = 0; i < row; i++)
    {
        if (mtx[i][col] == 1)
        {
            return false;
        }
    }

    //check diag1
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (mtx[i][j] == 1)
        {
            return false;
        }
    }
    //check diag2
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++)
    {
        if (mtx[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void build(vector<vector<int>> &mtx, int row, vector<string> &s)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        if (check(mtx, row, col) && s[row][col] != '*')
        {
            mtx[row][col] = 1;
            build(mtx, row + 1, s);
            mtx[row][col] = 0;
        }
    }
}

void solve()
{
    vector<string> s(8);
    for (int i = 0; i < s.size(); i++)
    {
        cin >> s[i];
    }
    ans = 0;
    vector<vector<int>> mtx(8, vector<int>(8, 0));
    build(mtx, 0, s);
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}