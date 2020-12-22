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

bool check(vector<vector<bool>> &visited, int i, int j)
{
    return i >= 0 && j >= 0 && i < 7 && j < 7 && !visited[i][j];
}

//D,U,L,R
void build(string &s, int ind, int i, int j, vector<vector<bool>> &visited)
{

    if (i < 0 || j < 0 || i >= 7 || j >= 7)
    {
        return;
    }
    if (ind == 48)
    {
        if (i == 6 && j == 0)
        {
            ans++;
        }
        return;
    }
    visited[i][j] = true;
    if (s[ind] == 'D')
    {
        if (i < 6 && !visited[i + 1][j])
            if (!(!check(visited, i + 2, j) && check(visited, i + 1, j + 1) && check(visited, i + 1, j - 1)))
                build(s, ind + 1, i + 1, j, visited);
    }
    else if (s[ind] == 'U')
    {
        if (i >= 1 && !visited[i - 1][j])
            if (!(!check(visited, i - 2, j) && check(visited, i - 1, j + 1) && check(visited, i - 1, j - 1)))
                build(s, ind + 1, i - 1, j, visited);
    }
    else if (s[ind] == 'L')
    {
        if (j >= 1 && !visited[i][j - 1])
            if (!(!check(visited, i, j - 2) && check(visited, i + 1, j - 1) && check(visited, i - 1, j - 1)))
                build(s, ind + 1, i, j - 1, visited);
    }
    else if (s[ind] == 'R')
    {
        if (j < 6 && !visited[i][j + 1])
            if (!(!check(visited, i, j + 2) && check(visited, i + 1, j + 1) && check(visited, i - 1, j + 1)))
                build(s, ind + 1, i, j + 1, visited);
    }
    else
    {
        if (i < 6 && !visited[i + 1][j])
            build(s, ind + 1, i + 1, j, visited);
        if (i >= 1 && !visited[i - 1][j])
            build(s, ind + 1, i - 1, j, visited);
        if (j >= 1 && !visited[i][j - 1])
            build(s, ind + 1, i, j - 1, visited);
        if (j < 6 && !visited[i][j + 1])
            build(s, ind + 1, i, j + 1, visited);
    }
    visited[i][j] = false;
}

void solve()
{
    string s;
    cin >> s;
    ans = 0;
    vector<vector<bool>> visited(7, vector<bool>(7, false));
    build(s, 0, 0, 0, visited);
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