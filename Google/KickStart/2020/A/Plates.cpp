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

// int n, k;
// map<array<int, 2>, int> mp;

// int build(vector<vector<int>> &b, int currStack, int platesLeft)
// {
//     if (platesLeft == 0)
//     {
//         return 0;
//     }
//     if (currStack == 0)
//     {
//         return b[currStack][min(platesLeft, k)];
//     }
//     if (mp.find({currStack, platesLeft}) != mp.end())
//     {
//         return mp[{currStack, platesLeft}];
//     }
//     int maxBeauty = 0;
//     for (int choose = 0; choose <= min(platesLeft, k); choose++)
//     {
//         if (currStack >= 1)
//             maxBeauty = max(maxBeauty, b[currStack][choose] + build(b, currStack - 1, platesLeft - choose));
//     }
//     return mp[{currStack, platesLeft}] = maxBeauty;
// }

void solve(int t)
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> b(n, vector<int>(k + 1));
    int val;
    for (int i = 0; i < n; i++)
    {
        b[i][0] = 0;
        for (int j = 1; j <= k; j++)
        {
            cin >> val;
            b[i][j] = b[i][j - 1] + val;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    for (int stack = 1; stack <= n; stack++)
    {
        for (int plates = 0; plates <= p; plates++)
        {
            for (int choose = 0; choose <= min(plates, k); choose++)
            {
                dp[stack][plates] = max(dp[stack][plates], b[stack - 1][choose] + dp[stack - 1][plates - choose]);
            }
        }
    }
    cout << "Case #" << t << ": " << dp[n][p] << endl;
}

int main()
{
    //     fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}