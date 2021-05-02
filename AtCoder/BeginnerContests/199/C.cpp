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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s.substr(0, n);
    string s2 = s.substr(n, n);
    int q;
    cin >> q;
    int t, a, b;
    while (q--)
    {
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1)
        {
            if (a < n && b < n)
            {
                swap(s1[a], s1[b]);
            }
            else if (a < n && b >= n)
            {
                b -= n;
                swap(s1[a], s2[b]);
            }
            else if (a >= n && b < n)
            {
                a -= n;
                swap(s2[a], s1[b]);
            }
            else
            {
                a -= n;
                b -= n;
                swap(s2[a], s2[b]);
            }
        }
        else
        {
            swap(s1, s2);
        }
    }
    cout << s1 << s2 << endl;
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