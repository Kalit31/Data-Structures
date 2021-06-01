#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 5;

/*
    Requires use of Mobius function
    Refer: https://discuss.codechef.com/t/coprime3-editorial/6051
*/

int cnt[N];
int p[N];
int dp[N];

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    memset(p, 0, sizeof(p));
    int n;
    cin >> n;
    vector<int> x(n);
    int maxN = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cnt[x[i]]++;
        maxN = max(maxN, x[i]);
    }
    for (int i = 2; i <= maxN; i++)
    {
        if (!p[i])
        {
            for (int j = i; j <= maxN; j += i)
            {
                if (!p[j])
                {
                    p[j] = i;
                }
            }
        }
    }

    ll ans = 0;

    for (int i = 1; i <= maxN; i++)
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
        for (int j = i; j <= maxN; j += i)
        {
            d += cnt[j];
        }
        ans += (d * (d - 1) * dp[i]) / 2;
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