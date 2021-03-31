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
    ll n, k;
    cin >> n >> k;

    vector<array<ll, 3>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin(), arr.end());
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + arr[i - 1][2];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll l = arr[i][0];
        ll r = arr[i][1];
        for (int j = i; j < n; j++)
        {
            r = max(r, arr[j][1]);
            ll curr = pref[j + 1] - pref[i];
            curr -= (r - l) * k;
            ans = max(ans, curr);
        }
    }
    //cout << "(" << i << "," << j << "): " << curr << " L:" << l << " R:" << r << endl;

    // for (ll i = 1; i < (1ll << n); i++)
    // {
    //     ll minTime = INT_MAX;
    //     ll maxTime = INT_MIN;
    //     ll profit = 0;
    //     for (ll j = 0; j < n; j++)
    //     {
    //         if (i & (1 << j))
    //         {
    //             minTime = min(minTime, arr[j][0]);
    //             maxTime = max(maxTime, arr[j][1]);
    //             profit += arr[j][2];
    //         }
    //     }

    //     if (maxTime >= minTime)
    //     {
    //         profit -= k * (maxTime - minTime);
    //         ans = max(ans, profit);
    //     }
    // }
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}