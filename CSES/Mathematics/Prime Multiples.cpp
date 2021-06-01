#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 5;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for (ll i = 1; i < (1ll << k); i++)
    {
        int count = __builtin_popcount(i);

        ll currNum = 1;
        for (int j = 0; j < k; j++)
        {
            if (i & (1 << j))
            {
                if (currNum > n / a[j])
                {
                    currNum = n + 1;
                    break;
                }
                currNum *= a[j];
            }
        }
        if (count % 2 == 1)
        {
            ans += (n / currNum);
        }
        else
        {
            ans -= (n / currNum);
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}