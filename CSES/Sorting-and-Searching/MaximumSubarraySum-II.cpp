#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll pre[n] = {0};

    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    multiset<ll> s1;

    s1.insert(0);
    ll ans = LONG_LONG_MIN;

    ans = max(ans, pre[a - 1]);

    int flag = 0;

    for (int i = a; i < n; i++)
    {

        if (i - b >= 0)
        {
            if (flag == 0)
            {

                auto it = s1.find(0);
                s1.erase(it);
                flag = 1;
            }
        }
        if (i - a >= 0)
            s1.insert(pre[i - a]);

        ans = max(ans,
                  pre[i] - *s1.begin());

        if (i - b >= 0)
        {
            auto it = s1.find(pre[i - b]);
            s1.erase(it);
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}