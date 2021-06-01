#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

ll modpow(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mid = (n - 1) / 2;
    ll ans = 0;
    for (int i = 0; i <= mid; i++)
    {
        int choices = s[i] - 'a';
        ans = (ans + (choices * modpow(k, mid - i, mod) % mod)) % mod;
    }
    string t = "";
    if (n & 1)
    {
        string a = s.substr(0, mid);
        t += a + s[mid];
        reverse(a.begin(), a.end());
        t += a;
        // deb(t);
    }
    else
    {
        string a = s.substr(0, mid + 1);
        t += a;
        reverse(a.begin(), a.end());
        t += a;
        //deb(t);
    }
    if (t < s)
    {
        ans = (ans + 1) % mod;
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}