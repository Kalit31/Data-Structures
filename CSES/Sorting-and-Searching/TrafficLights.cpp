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
    ll x, n;
    cin >> x >> n;
    ll pt;
    multiset<ll> parts;
    parts.insert(x);
    set<ll> p;
    p.insert(0);
    p.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> pt;
        auto upIt = p.upper_bound(pt);
        auto lowIt = p.lower_bound(pt);
        lowIt--;
        int diff = *upIt - *lowIt;
        //deb(diff);
        auto eraseIt = parts.find(diff);
        parts.erase(eraseIt);
        //deb(pt - *lowIt);
        parts.insert(pt - *lowIt);
        //deb(*upIt - pt);
        parts.insert(*upIt - pt);
        p.insert(pt);
        auto partsEnd = parts.end();
        partsEnd--;
        cout << *partsEnd << endl;
    }
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