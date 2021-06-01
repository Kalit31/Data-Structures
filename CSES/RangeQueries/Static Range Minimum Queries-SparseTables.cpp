#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

const int MAXN = (1 << 20);
const int MAXLOG = 20;

struct SparseTable
{
    int dp[MAXLOG][MAXN];
    int lg2[MAXN], n, P;

    void init(vector<int> &a)
    {
        memset(dp, 0, sizeof(dp));
        memset(lg2, 0, sizeof(lg2));
        n = a.size();
        P = (int)(log(n) / log(2));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = a[i];
        }

        for (int i = 2; i <= n; i++)
        {
            lg2[i] = lg2[i / 2] + 1;
        }

        for (int i = 1; i <= P; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                int l = dp[i - 1][j];
                int r = dp[i - 1][j + (1 << (i - 1))];
                dp[i][j] = min(l, r);
            }
        }
    }

    int minQuery(int l, int r)
    {
        int len = r - l + 1;
        int p = lg2[len];
        int lVal = dp[p][l];
        int rVal = dp[p][r - (1 << p) + 1];
        return min(lVal, rVal);
    }
};

SparseTable sparseTable;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sparseTable.init(x);
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        cout << sparseTable.minQuery(l, r) << endl;
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