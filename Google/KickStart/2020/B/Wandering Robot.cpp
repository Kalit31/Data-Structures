#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

void solveBrute()
{
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    vector<vector<double>> grid(w, vector<double>(h, 0));
    l--;
    u--;
    r--;
    d--;
    for (int i = l; i <= r; i++)
    {
        for (int j = u; j <= d; j++)
        {
            grid[i][j] = -1;
        }
    }
    grid[0][0] = 1;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (grid[i][j] == -1)
            {
                grid[i][j] = 0;
                continue;
            }
            if (i == w - 1 && j + 1 < h && grid[i][j + 1] != -1)
            {
                grid[i][j + 1] += grid[i][j];
            }
            else if (j == h - 1 && i + 1 < w && grid[i + 1][j] != -1)
            {
                grid[i + 1][j] += grid[i][j];
            }
            else
            {
                if (i + 1 < w && grid[i + 1][j] != -1)
                {
                    grid[i + 1][j] += 0.5 * grid[i][j];
                }
                if (j + 1 < h && grid[i][j + 1] != -1)
                {
                    grid[i][j + 1] += 0.5 * grid[i][j];
                }
            }
        }
    }

    cout << setprecision(10) << fixed << grid[w - 1][h - 1] << endl;
}

const int MAXN = 1000005;

double lfac[MAXN];
double pow2[MAXN];

double nCk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return exp(lfac[n] - lfac[k] - lfac[n - k] - (1.0 * n) * log(2));
}

void solve()
{
    int w, h, l, u, r, d;
    cin >> w >> h >> l >> u >> r >> d;
    w--;
    h--;
    l--;
    u--;
    r--;
    d--;
    double ans = 0.0;

    int ly = u;
    int lx = r;

    if (r < w)
    {
        double mult = 1.0;
        while (ly > 0)
        {
            ly--;
            lx++;

            if (lx >= w)
            {
                lx = w - 1;
                mult = 0.5;
            }
            ans += mult * nCk(lx + ly, lx);
        }
    }

    ly = l;
    lx = d;

    if (d < h)
    {
        double mult = 1.0;
        while (ly > 0)
        {
            ly--;
            lx++;

            if (lx >= h)
            {
                lx = h - 1;
                mult = 0.5;
            }
            ans += mult * nCk(lx + ly, lx);
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    lfac[0] = 0.0;
    for (int i = 1; i < MAXN; i++)
    {
        lfac[i] = lfac[i - 1] + log(i);
    }

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