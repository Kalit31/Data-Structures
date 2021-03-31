#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
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

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(4);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x]++;
    }
    double dp[n + 1][n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int three = 0; three <= n; three++)
    {
        for (int two = 0; two <= n; two++)
        {
            for (int one = 0; one <= n; one++)
            {
                int zero = n - (three + two + one);
                if (zero < 0 || zero == n)
                {
                    continue;
                }
                double ans = 1;
                if (three != 0)
                {
                    ans += ((1.0 * three) / n) * dp[three - 1][two + 1][one];
                }
                if (two != 0)
                {
                    ans += ((1.0 * two) / n) * dp[three][two - 1][one + 1];
                }
                if (one != 0)
                {
                    ans += ((1.0 * one) / n) * dp[three][two][one - 1];
                }
                ans = ans / (1 - (1.0 * zero) / n);
                dp[three][two][one] = ans;
            }
        }
    }
    cout << setprecision(10) << fixed << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
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