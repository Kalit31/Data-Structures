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
    ll n;
    cin >> n;
    vector<array<int, 2>> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i][0] >> pts[i][1];
    }
    ll m;
    cin >> m;
    vector<array<int, 2>> opt(m);
    vector<int> swaps(m + 1, 0);
    vector<int> x(m + 1, 0);
    vector<int> y(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> opt[i][0];
        if (opt[i][0] == 1)
        {
            swaps[i + 1] = swaps[i] + 1;
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        else if (opt[i][1] == 2)
        {
            swaps[i + 1] = swaps[i] - 1;
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        else if (opt[i][0] == 2)
        {
            cin >> opt[i][1];
            x[i] = 2 * opt[i][1] - x[i - 1];
            y[i] = y[i - 1];
        }
        else
        {
            cin >> opt[i][1];
            y[i] = 2 * opt[i][1] - y[i - 1];
            x[i] = x[i - 1];
        }
    }

    ll q;
    cin >> q;
    int a, b;
    while (q--)
    {
        cin >> a >> b;
        b--;
        array<int, 2> pt = pts[b];
        int xN = pt[0];
        int yN = pt[1];
        int sw = abs(swaps[a + 1]);
        if (sw % 2 == 0)
        {
            //cout<<
        }
        else
        {
            if (swaps[a + 1] < 0)
            {
            }
            else
            {
            }
        }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}