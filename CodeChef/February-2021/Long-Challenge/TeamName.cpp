#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
    vector<string> s(n);
    set<string> a;
    set<string> b;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        string t = s[i].substr(1);
        if (s[i][0] == 'a')
        {
            a.insert(t);
        }
        else
        {
            b.insert(t);
        }
    }
    int validAs = 0;
    int validBs = 0;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        string toFind = *it;
        if (b.find(toFind) == b.end())
        {
            validAs++;
        }
    }
    for (auto it = b.begin(); it != b.end(); it++)
    {
        string toFind = *it;
        if (a.find(toFind) == a.end())
        {
            validBs++;
        }
    }
    int cnt = validAs * validBs;
    cnt *= 2;
    cout << cnt << endl;
}

void solveNew()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<set<string>> a(26);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        string t = s[i].substr(1);
        int ch = s[i][0] - 'a';
        a[ch].insert(t);
    }
    vector<vector<int>> cnt(26, vector<int>(26, 0));
    for (int i = 0; i < 26; i++)
    {
        int sz = a[i].size();
        if (sz == 0)
            continue;
        for (auto it = a[i].begin(); it != a[i].end(); it++)
        {
            string toFind = *it;
            for (int j = 0; j < 26; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (a[j].size() == 0)
                {
                    continue;
                }
                if (a[j].find(toFind) == a[j].end())
                {
                    cnt[i][j]++;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i; j < 26; j++)
        {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    ans = ans * 2;
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
        solveNew();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}
