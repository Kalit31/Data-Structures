#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

void solve()
{
    int n;
    cin >> n;
    ll x, t;
    ll a = 0;
    ll b = INT_MIN;
    ll c = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> t;
        if (t == 1)
        {
            a += x;
            b += x;
            c += x;
        }
        else if (t == 2)
        {
            b = max(b, x);
            c = max(c, x);
        }
        else
        {
            b = min(b, x);
            c = min(c, x);
        }
    }
    // deb(a);
    // deb(b);
    // deb(c);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << min(c, max(b, a + x)) << endl;
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}