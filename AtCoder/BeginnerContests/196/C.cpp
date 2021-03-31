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
    ll n;
    cin >> n;
    int numDigits = 0;
    ll tN = n;
    while (tN)
    {
        numDigits++;
        tN /= 10;
    }
    ll curr = 1;
    ll ans = 0;
    for (int digits = 2; digits < numDigits; digits += 2)
    {
        ans += curr * 9;
        curr = curr * 10;
    }
    if (numDigits % 2 == 0)
    {
        int half = numDigits / 2;
        curr = pow(10, half);
        ll start = pow(10, half - 1);
        ll end = pow(10, half) - 1;
        for (ll i = start; i <= end; i++)
        {
            ll tmp = i * curr + i;
            if (tmp <= n)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}