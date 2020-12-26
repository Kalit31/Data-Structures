#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
string result = "";

bool dfs(vector<string> &grid, int i, int j, string path)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')
    {
        return false;
    }
    if (grid[i][j] == 'B')
    {
        if (result.empty())
        {
            result = path;
        }
        else
        {
            if (path.size() < result.size())
            {
                result = path;
            }
        }
        return true;
    }
    grid[i][j] = '#';
    bool found = dfs(grid, i + 1, j, path + 'D');
    found = found || dfs(grid, i - 1, j, path + 'U');
    found = found || dfs(grid, i, j - 1, path + 'L');
    found = found || dfs(grid, i, j + 1, path + 'R');
    grid[i][j] = '.';
    return found;
}

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, -1, 0, 1};
const char dir[4] = {'D', 'L', 'U', 'R'};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<string> path(n);

    int iA, jA;
    int iB, jB;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                iA = i;
                jA = j;
            }
            if (grid[i][j] == 'B')
            {
                iB = i;
                jB = j;
                grid[i][j] = '.';
            }
        }
        path[i] = string(m, '.');
    }
    /*deb(iA);
    deb(jA);
    deb(iB);
    deb(jB);*/
    queue<array<int, 2>> q;
    q.push({iA, jA});
    while (!q.empty())
    {
        array<int, 2> pt = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nextI = pt[0] + di[k];
            int nextJ = pt[1] + dj[k];
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || grid[nextI][nextJ] == '#')
            {
                continue;
            }
            q.push({nextI, nextJ});
            grid[nextI][nextJ] = '#';
            path[nextI][nextJ] = dir[k];
        }
    }
    /*
    //cout << "HERE" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << path[i][j];
        }
        cout << endl;
    }
    cout << path[iB][jB] << endl;
    cout << path[iB][jB] << endl;
    deb(iB);
    deb(jB);
    deb(iA);
    deb(jA);*/
    if (grid[iB][jB] == '#')
    {
        cout << "YES" << endl;
        string t;
        while (iB != iA || jB != jA)
        {
            t += path[iB][jB];
            //  deb(t);
            if (path[iB][jB] == 'U')
            {
                iB = iB + 1;
            }
            else if (path[iB][jB] == 'D')
            {
                iB = iB - 1;
            }
            else if (path[iB][jB] == 'L')
            {
                jB = jB + 1;
            }
            else if (path[iB][jB] == 'R')
            {
                jB = jB - 1;
            }
        }
        reverse(t.begin(), t.end());
        cout << t.size() << endl;
        cout << t << endl;
    }
    else
    {
        cout << "NO" << endl;
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}