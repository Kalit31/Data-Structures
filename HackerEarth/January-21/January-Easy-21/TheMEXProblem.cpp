// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define MOD 1000000007
const int N = 100005;
#define FAST                                                   \
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); \
    srand(time(NULL));
ll fre[N], ans[N];

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0, x; i < n; i++)
    {
        cin >> x;
        fre[x]++;
    }
    for (ll i = N - 1; i >= 1; i--)
    {
        ll sum = fre[i];
        for (ll j = i + i; j < N; j += i)
        {
            sum += fre[j];
        }
        ans[i] = (sum * (sum - 1)) / 2;
        for (ll j = i + i; j < N; j += i)
            ans[i] = (ans[i] - ans[j]);
    }
    for (ll i = 1; i < N; i++)
    {
        if (!ans[i])
        {
            cout << i << "\n";
            return;
        }
    }
}
int main()
{
    FAST;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(fre, 0, sizeof(fre));
        solve();
    }
}
