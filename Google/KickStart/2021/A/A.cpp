#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int currK = 0;
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            currK++;
    }
    cout << abs(currK - k) << endl;
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
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}