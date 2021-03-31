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
    int n, m, l;
    cin >> n >> m >> l;
    string s;
    cin >> s;
    string chr;
    cin >> chr;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> ct(n, vector<int>(n, 0));
    vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> u[i];
        --u[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> v[i];
        --v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        if (u[i] > v[i])
            swap(u[i], v[i]);
        //no. of edges between node u and v
        ++ct[u[i]][v[i]];
    }

    // dp[i][j] : no. of paths formed by the first (j+1) characters and ending at node i
    vector<vector<ll>> dp(n, vector<ll>(l, 0LL));

    for (int i = 0; i < n; ++i)
        dp[i][0] = chr[i] == s[0];

    for (int len = 1; len < l; ++len)
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[len] != chr[i])
                continue;
            for (int x : adj[i])
            {
                dp[i][len] = (dp[i][len] + dp[x][len - 1]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + dp[i][l - 1]) % mod;

    if (*min_element(begin(s), end(s)) == *max_element(begin(s), end(s)))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (chr[i] == s[0] and chr[j] == s[0])
                    ans = (ans + mod - my_pow(ct[i][j], l - 1, mod)) % mod;
            }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}