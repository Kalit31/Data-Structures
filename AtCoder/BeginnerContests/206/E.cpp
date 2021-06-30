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

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

const int N = 1e6 + 5;

/*
    Requires use of Mobius function
    Refer: https://discuss.codechef.com/t/coprime3-editorial/6051
*/

ll cnt[N];
ll p[N];
ll dp[N];

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    memset(p, 0, sizeof(p));
    ll l, r;
    cin >> l >> r;
    ll ans = (r - l + 1) * (r - l + 1);

    if (l == 1)
        ans -= (1 + (r - 1) * 2);

    l = max((ll)2, l);
    for (ll i = l; i <= r; i++)
    {
        cnt[i]++;
        ll j = i;
        while (j <= r)
        {
            if (i == j)
            {
                ans--;
            }
            else
            {
                ans -= 2;
            }
            j += i;
        }
    }
    // deb(ans);

    ll maxN = r;
    for (ll i = 2; i <= maxN; i++)
    {
        if (!p[i])
        {
            for (ll j = i; j <= maxN; j += i)
            {
                if (!p[j])
                {
                    p[j] = i;
                }
            }
        }
    }
    for (ll i = 1; i <= maxN; i++)
    {
        if (i == 1)
        {
            dp[i] = 1;
        }
        else
        {
            if (p[i / p[i]] == p[i])
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = -1 * dp[i / p[i]];
            }
        }

        // d stores the number of elements divisible by i
        // elements divisible by i : i,2*i,3*i,...
        ll d = 0;
        for (ll j = i; j <= maxN; j += i)
        {
            d += cnt[j];
        }
        ans -= (d * (d - 1) * dp[i]);
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}