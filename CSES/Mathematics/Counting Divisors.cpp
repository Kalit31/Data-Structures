#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int n = 1e6 + 5;

int cnt[n];

void SieveOfEratosthenes()
{
    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j += i)
        {
            cnt[j]++;
        }
    }
}

void solve()
{
    int x;
    cin >> x;
    cout << cnt[x] << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    SieveOfEratosthenes();
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}