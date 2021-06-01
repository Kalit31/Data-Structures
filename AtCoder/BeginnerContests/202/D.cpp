#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

const int N = 61;

void solve()
{
    vector<vector<ll>> pre(N, vector<ll>(N, 0));
    pre[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        pre[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i - 1][j - 1];
            //      cout << "pre[" << i << "][" << j << "]: " << pre[i][j] << endl;
        }
        pre[i][i] = 1;
    }
    int a, b;
    ll k;
    cin >> a >> b >> k;
    int n = a + b;
    for (int i = 0; i < n; i++)
    {
        ll comb = pre[a + b - 1][b];
        if (comb >= k)
        {
            cout << 'a';
            a--;
        }
        else
        {
            cout << 'b';
            b--;
            k -= comb;
        }
    }
    cout << endl;
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