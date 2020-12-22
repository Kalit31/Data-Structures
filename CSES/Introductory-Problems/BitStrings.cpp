#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
ll power(ll n)
{
    ll ans = 1;
    ll base = 2;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans % mod * base % mod) % mod;
            n--;
        }
        else
        {
            base = (base % mod * base % mod) % mod;
            n /= 2;
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    cout << power(n) << endl;
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