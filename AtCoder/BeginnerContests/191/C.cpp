#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
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
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }
    int cnt = 0;
    for (int i = 1; i < h - 1; i++)
    {
        bool found = false;
        for (int j = 1; j < w - 1; j++)
        {
            if (grid[i][j] == '#' && grid[i - 1][j] == '.')
            {
                if (!found)
                {
                    cnt++;
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
    }
    for (int i = 1; i < h - 1; i++)
    {
        bool found = false;
        for (int j = 1; j < w - 1; j++)
        {
            if (grid[i][j] == '#' && grid[i + 1][j] == '.')
            {
                if (!found)
                {
                    cnt++;
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
    }
    for (int i = 1; i < w - 1; i++)
    {
        bool found = false;
        for (int j = 1; j < h - 1; j++)
        {
            if (grid[j][i] == '#' && grid[j][i - 1] == '.')
            {
                if (!found)
                {
                    cnt++;
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
    }
    for (int i = 1; i < w - 1; i++)
    {
        bool found = false;
        for (int j = 1; j < h - 1; j++)
        {
            if (grid[j][i] == '#' && grid[j][i + 1] == '.')
            {
                if (!found)
                {
                    cnt++;
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
    }
    cout << cnt << endl;
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

/*
if (grid[i - 1][j] == '.' && grid[i][j - 1] == '.')
                {
                    cnt++;
                }
                if (grid[i][j - 1] == '.' && grid[i - 1][j] == '.')
                {
                    cnt++;
                }
                if (grid[i][j + 1] == '.' && grid[i - 1][j] == '.')
                {
                    cnt++;
                }
                if (grid[i + 1][j] == '.' && grid[i][j - 1] == '.')
                {
                    cnt++;
                }
                cout<<"("<<i
                deb(cnt);
*/