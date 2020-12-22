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
    ll k = n * (n + 1);
    if (k % 4 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    k = k / 4;
    cout << "YES" << endl;
    vector<ll> s1, s2;
    ll t;
    if (n % 4)
    {
        t = 1;
    }
    else
    {
        t = 0;
    }
    for (int i = 1; i <= (n - 1) / 4; i++)
    {
        s1.push_back(4 * i + 1 - t);
        s1.push_back(4 * i + 4 - t);
        s2.push_back(4 * i + 2 - t);
        s2.push_back(4 * i + 3 - t);
    }
    if (n % 4 == 0)
    {
        s1.push_back(1);
        s1.push_back(4);
        s2.push_back(2);
        s2.push_back(3);
    }
    else
    {
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
    }
    cout << s1.size() << endl;
    for (int num : s1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << s2.size() << endl;
    for (int num : s2)
    {
        cout << num << " ";
    }
    cout << endl;
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