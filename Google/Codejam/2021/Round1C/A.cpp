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
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    vector<int> diff;

    for (int i = 1; i < n; i++)
    {
        if (p[i] != p[i - 1])
        {
            diff.push_back(p[i] - p[i - 1] - 1);
        }
    }
    sort(diff.begin(), diff.end(), greater<int>());

    int poss1 = p[0] - 1;
    int poss2 = k - p[n - 1];

    int maxProb = max(0, poss1 + poss2);

    if (diff.size() >= 1)
    {
        maxProb = max(maxProb, max(poss1, poss2) + (diff[0] + 1) / 2);
        maxProb = max(maxProb, diff[0]);
    }
    if (diff.size() >= 2)
    {
        maxProb = max(maxProb, (diff[0] + 1) / 2 + (diff[1] + 1) / 2);
    }
    cout << (1.0 * maxProb) / k << endl;
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