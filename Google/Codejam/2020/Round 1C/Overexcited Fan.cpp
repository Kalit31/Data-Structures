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
    int x, y;
    cin >> x >> y;
    string m;
    cin >> m;
    int currX = x;
    int currY = y;
    if ((x + y) == 0)
    {
        cout << 0 << endl;
        return;
    }
    int currTime = 1;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == 'N')
        {
            currY++;
        }
        else if (m[i] == 'E')
        {
            currX++;
        }
        else if (m[i] == 'W')
        {
            currX--;
        }
        else if (m[i] == 'S')
        {
            currY--;
        }
        int timeToReach = abs(currX) + abs(currY);
        if (timeToReach <= currTime)
        {
            cout << currTime << endl;
            return;
        }
        currTime++;
    }
    cout << "IMPOSSIBLE" << endl;
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