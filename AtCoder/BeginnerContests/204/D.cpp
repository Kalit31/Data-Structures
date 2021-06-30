#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
// #define deb1(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template <typename... Args>
// void logger(string vars, Args &&...values)
// {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ", "));
// }
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
    int n;
    cin >> n;
    vector<int> t(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        tot += t[i];
    }

    if (n == 1)
    {
        cout << t[0] << endl;
        return;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(tot + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= tot; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - t[i] >= 0)
            {
                dp[i][j] = dp[i][j] | dp[i - 1][j - t[i]];
            }
        }
    }
    int a;
    int b;
    int diff = INT_MAX;

    for (int i = 1; i <= tot; i++)
    {
        if (dp[n][i])
        {
            int f = i;
            int s = tot - f;
            if (abs(f - s) < diff)
            {
                diff = abs(f - s);
                a = f;
                b = s;
            }
        }
    }

    cout << max(a, b) << endl;
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