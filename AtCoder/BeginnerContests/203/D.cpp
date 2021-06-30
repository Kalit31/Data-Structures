#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

vector<vector<int>> arr;
int n, k;

bool poss(int val)
{
    int cnt = ((k * k) / 2) + 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > val)
            {
                dp[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    bool ok = false;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            int currCnt = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
            if (currCnt < cnt)
            {
                ok = true;
                break;
            }
        }
    }
    return ok;
}

void solve()
{
    cin >> n >> k;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int lo = 0;
    int hi = 1e9 + 5;
    int ans = hi;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (poss(mid))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}