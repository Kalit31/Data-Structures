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

int findCost(vector<int> l)
{
    int n = l.size();
    int cost = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        int toFind = n + 1;
        int toFindInd = -1;
        for (int j = i; j < n; j++)
        {
            if (l[j] < toFind)
            {
                toFind = l[j];
                toFindInd = j;
            }
        }
        reverse(l.begin() + i, l.begin() + (toFindInd + 1));
        cost += toFindInd - (i) + 1;
    }
    return cost;
}

void solveBrute()
{
    int n, c;
    cin >> n >> c;
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = i + 1;
    }

    do
    {
        if (c == findCost(result))
        {
            for (int x : result)
            {
                cout << x << " ";
            }
            cout << endl;
            return;
        }

    } while (next_permutation(result.begin(), result.end()));
    cout << "IMPOSSIBLE" << endl;
}

int rem;

vector<int> build(set<int> &s)
{
    int n = s.size();
    vector<int> res;

    if (rem == (n - 1))
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            res.push_back(*it);
        }

        return res;
    }
    else
    {
        int maxN = n;
        int select = rem - (n - 1) + 1;
        if (select > maxN)
        {
            select = maxN;
        }
        rem -= select;
        auto it = s.begin();
        int val = *it;
        s.erase(it);
        vector<int> nextRes = build(s);
        int i = 0;
        for (; i < (select - 1); i++)
        {
            res.push_back(nextRes[i]);
        }
        reverse(res.begin(), res.end());
        res.push_back(val);
        for (; i < nextRes.size(); i++)
        {
            res.push_back(nextRes[i]);
        }
    }
    return res;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    int minCost = n - 1;
    int maxCost = (n * (n + 1)) / 2 - 1;
    if (c < minCost || c > maxCost)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    rem = c;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    vector<int> result = build(s);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
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

    return 0;
}
