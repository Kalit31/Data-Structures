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
    int n;
    cin >> n;
    vector<vector<int>> ants(n);
    unordered_map<int, int> freq;
    vector<int> dist;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> ant(m);
        for (ll j = 0; j < m; j++)
        {
            cin >> ant[j];
            freq[abs(ant[j])]++;
            if (freq[abs(ant[j])] == 1)
            {
                dist.push_back(abs(ant[j]));
            }
        }
        ants[i] = ant;
    }
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second > 1)
        {
            ans++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll pos = 0;
        ll neg = 0;
        vector<array<int, 2>> s;
        for (auto a : ants[i])
        {
            if (a < 0)
            {
                neg++;
                s.push_back({abs(a), -1});
            }
            else
            {
                pos++;
                s.push_back({abs(a), 1});
            }
        }
        sort(s.begin(), s.end());
        for (auto p : s)
        {
            if (p[1] == -1)
            {
                neg--;
            }
            else
            {
                pos--;
            }
            if (freq[p[0]] > 1)
            {
                if (p[1] == -1)
                {
                    ans += neg;
                }
                else
                {
                    ans += pos;
                }
            }
            else
            {
                if (p[1] == 1)
                {
                    ans += neg;
                }
                else
                {
                    ans += pos;
                }
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}