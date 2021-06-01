#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 5;

ll fact[N];

ll my_pow(ll a, ll n, ll m)
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

ll modInverse(ll num)
{
    return my_pow(num, mod - 2, mod);
}

void solve()
{
    string s;
    cin >> s;
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vector<int> freq(26, 0);
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }
    ll ans = fact[s.size()];
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 1)
            ans = (ans * modInverse(fact[freq[i]])) % mod;
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}