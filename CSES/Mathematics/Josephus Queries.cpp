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

int build(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }
    if (2 * k <= (n + 1))
    {
        int ans = (2 * k) % n;
        if (ans == 0)
        {
            return 2 * k;
        }
        return ans;
    }
    int movesDone = (n + 1) / 2;
    int movesLeft = k - movesDone;
    int ans = build(n / 2, movesLeft);

    return n % 2 == 0 ? 2 * ans - 1 : 2 * ans + 1;
}

void solve()
{
    int q;
    cin >> q;

    int n, k;
    while (q--)
    {
        cin >> n >> k;
        cout << build(n, k) << endl;
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