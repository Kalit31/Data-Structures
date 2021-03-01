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

const int N = 5e5 + 10;
vector<int> arr;

//O(N^3) solution
int findOld(vector<int> &a, vector<array<int, 2>> &queries, int m)
{
    int wins = 0;
    vector<int> win(m + 1, 0);
    //O(n^3)
    for (int i = 0; i < queries.size(); i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        arr.clear();
        for (int j = 0; j < a[l]; j++)
        {
            arr[j] = 1;
        }
        //O(n^2)
        for (int j = a[l]; j <= m; j++)
        {
            bool winPoss = false;
            //O(n)
            for (int k = l; k <= r; k++)
            {
                if (j - a[k] >= 0 && arr[j - a[k]] == 1)
                {
                    winPoss = true;
                    break;
                }
            }
            if (winPoss)
            {
                arr[j] = 0;
            }
            else
            {
                arr[j] = 1;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (arr[i] == 0)
            {
                win[i]++;
            }
        }
    }
    return *max_element(win.begin(), win.end());
}

int find(vector<int> &a, vector<array<int, 2>> &queries, int m)
{
    map<array<int, 2>, int> mp;
    for (int i = 0; i < queries.size(); i++)
    {
        int l = a[queries[i][0]];
        int r = a[queries[i][1]];
        if (m >= l)
        {
            arr[l]++;
            arr[m + 1]--;
            if (m >= r)
            {
                mp[{l, r}]++;
            }
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int l = it->first[0];
        int r = it->first[1];
        int cnt = it->second;
        int ptr1 = l + r;
        while (ptr1 + l < N)
        {
            arr[ptr1] -= cnt;
            arr[ptr1 + l] += cnt;
            ptr1 += l + r;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        arr[i] = arr[i] + arr[i - 1];
        ans = max(ans, arr[i]);
    }
    return ans;
}

void solve()
{
    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<array<int, 2>> queries(q);
    int l, r;
    int k = 0;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        queries[k++] = {l, r};
    }
    arr.clear();
    arr.resize(N, 0);

    int optimal = find(a, queries, m);
    cout << optimal << endl;
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
    //cout << "Done in " << clock() / CLOCKS_PER_SEC << "sec" << endl;
    return 0;
}