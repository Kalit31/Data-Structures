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
    string s;
    cin >> s;
    int n = s.size();
    ll longRep = 1;
    char ch = s[0];
    ll currRep = 1;
    for (int i = 1; i < n; i++)
    {
        if (ch == s[i])
        {
            currRep++;
            longRep = max(longRep, currRep);
        }
        else
        {
            currRep = 1;
            ch = s[i];
        }
    }
    cout << longRep << endl;
}

int main()
{
    fast;
    /*#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif*/

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}