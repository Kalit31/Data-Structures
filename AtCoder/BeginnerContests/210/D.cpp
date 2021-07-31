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

vector<vector<ll>> rotateGrid(vector<vector<ll>> &a)
{
    int h = a.size();
    int w = a[0].size();

    vector<vector<ll>> b(w, vector<ll>(h));

    for (int i = 0; i < h; i++)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            b[w - 1 - j][i] = a[i][j];
        }
    }

    return b;
}

void solve()
{
    int h, w;
    ll c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    ll ans = INF;

    for (int k = 0; k < 2; k++)
    {
        vector<vector<ll>> dp1(a.size() + 1, vector<ll>(a[0].size() + 1, INF));
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= a[0].size(); j++)
            {
                dp1[i][j] = min(a[i - 1][j - 1], min(dp1[i - 1][j] + c, dp1[i][j - 1] + c));
            }
        }

        vector<vector<ll>> dp2(a.size() + 1, vector<ll>(a[0].size() + 1, INF));
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= a[0].size(); j++)
            {
                dp2[i][j] = a[i - 1][j - 1] + c + min(dp1[i - 1][j], dp1[i][j - 1]);
                ans = min(ans, dp2[i][j]);
            }
        }
        a = rotateGrid(a);
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}