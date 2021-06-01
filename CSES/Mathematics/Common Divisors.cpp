#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> freq(N, 0);
    int maxEle = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
        maxEle = max(maxEle, x);
    }

    int ans = 1;
    for (int i = 2; i <= maxEle; i++)
    {
        int cnt = 0;
        for (int j = i; j <= maxEle; j += i)
        {
            cnt += freq[j];
        }
        if (cnt >= 2)
        {
            ans = i;
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}