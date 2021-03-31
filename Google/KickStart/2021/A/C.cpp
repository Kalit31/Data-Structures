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

ll ans = 0;

bool isFine(vector<vector<int>> &grid, int i, int j)
{
    int r = grid.size();
    int c = grid[0].size();
    if (i - 1 >= 0)
    {
        int diff = grid[i][j] - grid[i - 1][j];
        if (diff > 1)
        {
            return false;
        }
    }

    if (j - 1 >= 0)
    {
        int diff = grid[i][j] - grid[i][j - 1];
        if (diff > 1)
        {
            return false;
        }
    }
    if (i + 1 < r)
    {
        int diff = grid[i][j] - grid[i + 1][j];
        if (diff > 1)
        {
            return false;
        }
    }
    if (j + 1 < c)
    {
        int diff = grid[i][j] - grid[i][j + 1];
        if (diff > 1)
        {
            return false;
        }
    }
    return true;
}

struct CompareHeight
{
    bool operator()(array<int, 3> const &a, array<int, 3> const &b)
    {
        return a[0] < b[0];
    }
};

priority_queue<array<int, 3>, vector<array<int, 3>>, CompareHeight> q;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
{
    int r = grid.size();
    int c = grid[0].size();

    if (i < 0 || j < 0 || i >= r || j >= c)
    {
        return;
    }

    if (i - 1 >= 0)
    {
        if (!visited[i - 1][j])
        {
            int diff = grid[i][j] - grid[i - 1][j];
            if (diff > 1)
            {
                grid[i - 1][j] += (diff - 1);
                ans += (diff - 1);
                q.push({grid[i - 1][j], i - 1, j});
            }
        }
    }

    if (j - 1 >= 0)
    {
        if (!visited[i][j - 1])
        {
            int diff = grid[i][j] - grid[i][j - 1];
            if (diff > 1)
            {
                grid[i][j - 1] += (diff - 1);
                ans += (diff - 1);
                q.push({grid[i][j - 1], i, j - 1});
            }
        }
    }
    if (i + 1 < r)
    {
        if (!visited[i + 1][j])
        {
            int diff = grid[i][j] - grid[i + 1][j];
            if (diff > 1)
            {
                grid[i + 1][j] += (diff - 1);
                ans += (diff - 1);
                q.push({grid[i + 1][j], i + 1, j});
            }
        }
    }
    if (j + 1 < c)
    {

        if (!visited[i][j + 1])
        {

            int diff = grid[i][j] - grid[i][j + 1];
            if (diff > 1)
            {
                grid[i][j + 1] += (diff - 1);
                ans += (diff - 1);
                q.push({grid[i][j + 1], i, j + 1});
            }
        }
    }
}

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            q.push({grid[i][j], i, j});
        }
    }
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    ans = 0;
    while (!q.empty())
    {
        array<int, 3> curr = q.top();
        q.pop();

        if (visited[curr[1]][curr[2]] || isFine(grid, curr[1], curr[2]))
            continue;

        dfs(grid, visited, curr[1], curr[2]);
        visited[curr[1]][curr[2]] = true;
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
    return 0;
}
//cout << "PUSHING (" << grid[i][j] << "," << i << "," << j << ")" << endl;
//  cout << "POPPING (" << curr[0] << "," << curr[1] << "," << curr[2] << ")" << endl;

//cout << "IN" << endl;
// cout << "(" << i << "," << j << ")" << endl;