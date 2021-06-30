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

int n, m, k;
bool check(vector<array<int, 2>> &moves, int mid)
{
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i <= mid; i++)
    {
        grid[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] += (i ? grid[i - 1][j] : 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] += (j ? grid[i][j - 1] : 0);
        }
    }

    for (int i = k - 1; i < n; i++)
    {
        for (int j = k - 1; j < m; j++)
        {
            int ans = grid[i][j] - (i >= k ? grid[i - k][j] : 0) - (j >= k ? grid[i][j - k] : 0) + ((i >= k && j >= k) ? grid[i - k][j - k] : 0);
            if (abs(ans) == k * k)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m >> k;
    vector<array<int, 2>> moves(n * m);
    int x, y;
    for (int move = 0; move < n * m; move++)
    {
        cin >> x >> y;
        x--;
        y--;
        moves[move] = {x, y};
    }
    int ans = -1;
    int lo = 0;
    int hi = n * m - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(moves, mid))
        {
            hi = mid - 1;
            ans = mid % 2 == 0 ? 1 : 0;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (ans == -1)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << (ans == 1 ? "Alice" : "Bob") << endl;
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