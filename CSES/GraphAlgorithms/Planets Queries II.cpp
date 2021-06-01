#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i]--;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        //deb(a);
        //deb(b);
        cout << flush;
        int moves = 0;
        vector<bool> visited(n, false);
        visited[a] = true;
        bool poss = true;
        while (a != b)
        {
            moves++;
            a = t[a];
            if (visited[a])
            {
                poss = false;
                break;
            }
            visited[a] = true;
        }
        cout << (poss ? moves : -1) << endl;
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
    return 0;
}