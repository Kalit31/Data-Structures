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

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    ll y;
    cin >> y;
    string year = to_string(y);
    ll result = LONG_LONG_MAX;
    for (int i = 1; i <= year.size(); i++)
    {
        ll num = stol(year.substr(0, i));
        // deb(num);
        //if year is roaring
        num++;
        string ans1 = to_string(num);
        if (i == year.size())
        {
            ans1 = to_string(LONG_LONG_MAX);
        }
        else
        {
            while (stol(ans1) <= y)
            {
                num++;
                ans1 += to_string(num);
            }
        }
        // deb(ans1);
        //if year is not roaring
        num = stol(year.substr(0, i));
        string ans2 = to_string(num);
        while (stol(ans2) <= y)
        {
            num++;
            ans2 += to_string(num);
        }
        // deb(ans2);
        ll ans = min(stol(ans1), stol(ans2));
        result = min(result, ans);
    }
    cout << result << endl;
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