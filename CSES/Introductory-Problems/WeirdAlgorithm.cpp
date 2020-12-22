#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    ll n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << 1 << endl;
}

int main()
{
    fast;

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}