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
    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n, vector<int>(n));

    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '.')
            {
                forest[i][j] = 0;
            }
            else
            {
                forest[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            forest[i][j] += (i > 0 ? forest[i - 1][j] : 0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            forest[i][j] += (j > 0 ? forest[i][j - 1] : 0);
        }
    }
    int y1, x1, y2, x2;
    while (q--)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        y2--;
        x2--;
        int ans = forest[y2][x2];
        ans -= (x1 > 0 ? forest[y2][x1 - 1] : 0);
        ans -= (y1 > 0 ? forest[y1 - 1][x2] : 0);
        ans += (x1 > 0 && y1 > 0 ? forest[y1 - 1][x1 - 1] : 0);
        cout << ans << endl;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}