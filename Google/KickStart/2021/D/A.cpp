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
         Never use an iterator after erasing it
*/

void solve()
{
    vector<vector<int>> grid(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        cin >> grid[0][i];
    }
    cin >> grid[1][0] >> grid[1][2];
    grid[1][1] = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        cin >> grid[2][i];
    }
    int ans = 0;
    //1st row
    int sum = grid[0][0] + grid[0][2];
    if (sum % 2 == 0)
    {
        if (grid[0][1] == sum / 2)
        {
            ans++;
        }
    }
    //3rd row
    sum = grid[2][0] + grid[2][2];
    if (sum % 2 == 0)
    {
        if (grid[2][1] == sum / 2)
        {
            ans++;
        }
    }

    //1st col
    sum = grid[0][0] + grid[2][0];
    if (sum % 2 == 0)
    {
        if (grid[1][0] == sum / 2)
        {
            ans++;
        }
    }

    //3rd col
    sum = grid[0][2] + grid[2][2];
    if (sum % 2 == 0)
    {
        if (grid[1][2] == sum / 2)
        {
            ans++;
        }
    }
    //deb(ans);
    map<int, int> cnt;
    //2nd row
    sum = grid[1][0] + grid[1][2];
    if (sum % 2 == 0)
    {
        cnt[sum / 2]++;
    }
    //2nd col
    sum = grid[0][1] + grid[2][1];
    if (sum % 2 == 0)
    {
        cnt[sum / 2]++;
    }
    //1st diag
    sum = grid[0][0] + grid[2][2];
    if (sum % 2 == 0)
    {
        cnt[sum / 2]++;
    }
    //2nd diag
    sum = grid[0][2] + grid[2][0];
    if (sum % 2 == 0)
    {
        cnt[sum / 2]++;
    }
    int maxCnt = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        maxCnt = max(maxCnt, it->second);
    }
    cout << ans + maxCnt << endl;
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}