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
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

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
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 0)
                continue;
            int left = 1;
            int right = 1;
            int up = 1;
            int down = 1;
            for (int k = j + 1; k < c; k++)
            {
                if (grid[i][k] == 0)
                    break;
                right++;
            }
            for (int k = j - 1; k >= 0; k--)
            {
                if (grid[i][k] == 0)
                    break;
                left++;
            }
            for (int k = i + 1; k < r; k++)
            {
                if (grid[k][j] == 0)
                    break;
                down++;
            }

            for (int k = i - 1; k >= 0; k--)
            {
                if (grid[k][j] == 0)
                    break;
                up++;
            }
            // cout << "(" << i << "," << j << "): " << ans << endl;
            int k = 2;
            while (k <= left && k * 2 <= up)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= up && k * 2 <= left)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= right && k * 2 <= up)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= up && k * 2 <= right)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= left && k * 2 <= down)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= down && k * 2 <= left)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= right && k * 2 <= down)
            {
                ans++;
                k++;
            }
            k = 2;
            while (k <= down && k * 2 <= right)
            {
                ans++;
                k++;
            }

            // cout << "(" << i << "," << j << "): " << ans << endl;
        }
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}
/*
 int m1 = min(left, up);
            int m2 = max(left, up);
            while (k <= m1 && k * 2 <= m2)
            {
                ans++;
                k++;
            }
            m1 = min(right, up);
            m2 = max(right, up);
            k = 2;
            while (k <= m1 && k * 2 <= m2)
            {
                ans++;
                k++;
            }
            m1 = min(left, down);
            m2 = max(left, down);
            k = 2;
            while (k <= m1 && k * 2 <= m2)
            {
                ans++;
                k++;
            }
            m1 = min(right, down);
            m2 = max(right, down);
            k = 2;
            while (k <= m1 && k * 2 <= m2)
            {
                ans++;
                k++;
            }
*/