#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 2e6 + 5;

//Dearrangement problem

void solve()
{
    int n;
    cin >> n;
    vector<ll> d(n + 1);
    d[1] = 0;
    d[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        d[i] = ((i - 1) * ((d[i - 1] + d[i - 2]) % mod)) % mod;
    }
    cout << d[n] << endl;
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