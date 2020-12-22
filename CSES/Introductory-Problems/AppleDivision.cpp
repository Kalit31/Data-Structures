#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX
ll minDiff = LONG_LONG_MAX;
ll totalSum = 0;

void build(vector<ll> &wts, int i, ll currSum)
{
    if (i == wts.size())
    {
        ll wt2 = totalSum - currSum;
        minDiff = min(minDiff, abs(currSum - wt2));
        return;
    }
    build(wts, i + 1, currSum);
    build(wts, i + 1, currSum + wts[i]);
}

void solve()
{
    ll n;
    cin >> n;
    totalSum = 0;
    vector<ll> wts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wts[i];
        totalSum += wts[i];
    }
    ll currSum = 0;
    build(wts, 0, currSum);
    cout << minDiff << endl;
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