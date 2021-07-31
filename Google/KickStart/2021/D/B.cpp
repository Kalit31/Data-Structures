#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<array<ll, 2>> intvl(n);
    map<ll, ll> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> intvl[i][0] >> intvl[i][1];
        freq[intvl[i][0] + 1]++;
        freq[intvl[i][1]]--;
    }

    vector<array<ll, 2>> a;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        a.push_back({it->first, it->second});
    }

    for (int i = 1; i < a.size(); i++)
    {
        a[i][1] = a[i][1] + a[i - 1][1];
    }

    ll ans = n;

    map<ll, ll> freq2;
    for (int i = 0; i < a.size() - 1; i++)
    {
        freq2[a[i][1]] += a[i + 1][0] - a[i][0];
    }

    priority_queue<array<ll, 2>> pq;

    for (auto it = freq2.begin(); it != freq2.end(); it++)
    {
        pq.push({it->first, it->second});
    }

    while (!pq.empty() && c)
    {
        auto curr = pq.top();
        pq.pop();
        ll minN = min(c, curr[1]);
        c -= minN;
        ans += minN * curr[0];
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}