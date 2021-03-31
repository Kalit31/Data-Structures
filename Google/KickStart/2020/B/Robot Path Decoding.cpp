#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000000
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
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

array<ll, 2> find(string s, int l, int r)
{
    array<ll, 2> ans = {0, 0};
    for (int i = l; i <= r; i++)
    {
        if (s[i] == 'N')
        {
            ans[1]--;
        }
        else if (s[i] == 'E')
        {
            ans[0]++;
        }
        else if (s[i] == 'W')
        {
            ans[0]--;
        }
        else if (s[i] == 'S')
        {
            ans[1]++;
        }
        else
        {
            array<ll, 2> next;
            ll num = s[i] - '0';
            int openB = 1;
            int j = i + 1;
            while (openB > 0)
            {
                j++;
                if (s[j] == '(')
                {
                    openB++;
                }
                else if (s[j] == ')')
                {
                    openB--;
                }
            }
            next = find(s, i + 2, j - 1);
            ans[0] = (ans[0] + (num * next[0]));
            ans[1] = (ans[1] + (num * next[1]));
            i = j;
        }
    }
    ans[0] = (ans[0] + mod) % mod;
    ans[1] = (ans[1] + mod) % mod;
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    array<ll, 2> p = find(s, 0, s.size() - 1);
    cout << p[0] + 1 << " " << p[1] + 1 << endl;
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