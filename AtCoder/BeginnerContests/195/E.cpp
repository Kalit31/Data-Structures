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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string x;
    cin >> x;
    vector<bool> dp(7, false);
    dp[0] = true;

    for (int i = n - 1; i >= 0; i--)
    {
        vector<bool> tdp(7, false);
        if (x[i] == 'A')
        {
            for (int j = 0; j < 7; j++)
            {
                int a = (j * 10) % 7;
                int b = (j * 10 + (s[i] - '0')) % 7;
                tdp[j] = dp[a] && dp[b];
            }
        }
        else
        {
            for (int j = 0; j < 7; j++)
            {
                int a = (j * 10) % 7;
                int b = (j * 10 + (s[i] - '0')) % 7;
                tdp[j] = dp[a] || dp[b];
            }
        }
        for (int i = 0; i < 7; i++)
        {
            cout << tdp[i] << " ";
        }
        cout << endl;
        dp = tdp;
    }
    if (dp[0])
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
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