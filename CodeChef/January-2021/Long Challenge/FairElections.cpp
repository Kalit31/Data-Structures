#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
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
    ll n, m;
    cin >> n >> m;
    //john
    vector<ll> a(n);
    ll john = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        john += a[i];
    }
    sort(a.begin(), a.end());
    //jack
    vector<ll> b(m);
    ll jack = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        jack += b[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    int ptr = 0;
    while (ptr < min(n, m) && john <= jack)
    {
        john += (b[ptr] - a[ptr]);
        jack += (a[ptr] - b[ptr]);
        ptr++;
    }
    if (john <= jack)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ptr << endl;
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}