#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/
const int N = 1e5 + 5;
ll dp[N][8];
string tgt = "chokudai";

ll build(string &s, int idx, int tIdx)
{
    int n = s.size();
    if (tIdx == 8)
    {
        return 1;
    }
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][tIdx] != -1)
    {
        return dp[idx][tIdx];
    }
    ll ans = 0;
    //if s[idx] match with tgt[tIdx]
    if (s[idx] == tgt[tIdx])
        ans = (ans + build(s, idx + 1, tIdx + 1)) % mod;

    ans = (ans + build(s, idx + 1, tIdx)) % mod;

    return dp[idx][tIdx] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    cout << build(s, 0, 0) << endl;
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