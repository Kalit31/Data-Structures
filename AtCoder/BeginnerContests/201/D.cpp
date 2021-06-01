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

const int N = 2005;

int grid[N][N];
int dp[N][N];
int h, w;

void solve()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '+' ? 1 : -1;
        }
    }

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1)
            {
                continue;
            }
            int isOdd = (i + j) % 2;
            if (!isOdd)
            {
                //Takahashi's turn.
                // will try to increase dp[i][j] as much as possible
                dp[i][j] = INT_MIN;
                if (i + 1 < h)
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] + grid[i + 1][j]);
                }
                if (j + 1 < w)
                {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + grid[i][j + 1]);
                }
            }
            else
            {
                //Aoki's turn
                // will try to decrease dp[i][j] as much as possible
                dp[i][j] = INT_MAX;
                if (i + 1 < h)
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] - grid[i + 1][j]);
                }
                if (j + 1 < w)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] - grid[i][j + 1]);
                }
            }
        }
    }

    int score = dp[0][0];
    if (score > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (score == 0)
    {
        cout << "Draw" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
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