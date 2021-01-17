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
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> arr(n);
    vector<int> arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr2[i] = arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());
    ll cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i][1] < arr[i - 1][1])
        {
            cnt++;
        }
    }
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        a--;
        b--;
        int n1 = arr2[a];
        int n2 = arr2[b];
        if (n1 > n2)
        {
            swap(n1, n2);
        }
        int idx1 = arr[n1 - 1][1];
        int idx2 = arr[n2 - 1][1];
        if (n1 == 1)
        {
            if (idx1 > arr[n1][1])
            {
                cnt--;
            }
        }
        else
        {
            if (idx1 < arr[n1 - 2][1])
            {
                cnt--;
            }
            if (idx1 > arr[n1][1])
            {
                cnt--;
            }
        }
        if (n2 == n)
        {
            if (idx2 < arr[n2 - 2][1])
            {
                cnt--;
            }
        }
        else
        {
            if (idx2 < arr[n2 - 2][1])
            {
                cnt--;
            }
            if (idx2 > arr[n2][1])
            {
                cnt--;
            }
        }
        // swap(arr[n1-1][1],a)
        swap(arr2[a], arr2[b]);
        cout << cnt << endl;
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}