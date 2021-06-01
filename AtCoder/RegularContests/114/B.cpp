#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

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
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        f[i]--;
    }
    vector<int> visited(n);
    int cycles = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int curr = i;
            while (visited[curr] == 0)
            {
                visited[curr] = 1;
                curr = f[curr];
            }
            if (visited[curr] == 1)
                cycles++;
            curr = i;
            while (visited[curr] == 1)
            {
                visited[curr] = 2;
                curr = f[curr];
            }
        }
    }
    //deb(cycles);
    ll ans = (my_pow(2, cycles, mod) + mod - 1) % mod;
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