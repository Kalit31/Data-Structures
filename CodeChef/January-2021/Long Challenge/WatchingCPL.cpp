#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

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

bool check(vector<ll> &h, ll n, ll k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += h[i];

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (h[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - h[i - 1]];
        }
    }

    int diff = INT_MAX;

    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    if ((sum - diff) / 2 >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ll build(vector<ll> &h, ll k)
{
    ll n = h.size();
    ll curr = 0;
    ll i = 0;
    while (i < n && curr < 2 * k)
    {
        curr += h[i];
        i++;
    }
    //deb(i);
    while (i <= n)
    {
        if (check(h, i, k))
        {
            return i;
        }
        else
        {

            i++;
        }
    }
    return -1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end(), greater<int>());
    /* for (int i = 0; i <= k; i++)
    {
        dp[0][k] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    prefix[0] = h[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + h[i - 1];
    }*/
    cout << build(h, k) << endl;
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
    return 0;
}