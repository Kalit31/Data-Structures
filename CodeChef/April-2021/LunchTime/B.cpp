#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

void solve()
{
    ll n, w, wr;
    cin >> n >> w >> wr;
    vector<ll> wt(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        mp[wt[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ll val = it->first;
        ll cnt = (it->second) / 2;
        wr += 2 * val * cnt;
        if (wr >= w)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}