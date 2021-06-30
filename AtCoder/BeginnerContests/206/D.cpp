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
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

vector<int> dsuf;
vector<int> sizeComp;

int find(int v)
{
    if (dsuf[v] == v)
        return v;
    return dsuf[v] = find(dsuf[v]);
}

void union_op(int pA, int pB)
{
    if (sizeComp[pA] > sizeComp[pB])
    {
        dsuf[pB] = dsuf[pA];
        sizeComp[pA] += sizeComp[pB];
    }
    else
    {
        dsuf[pA] = dsuf[pB];
        sizeComp[pB] += sizeComp[pA];
    }
}

const int N = 2e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dsuf.resize(N);
    for (int i = 0; i < N; i++)
    {
        dsuf[i] = i;
    }
    sizeComp.resize(N);
    for (int i = 0; i < N; i++)
    {
        sizeComp[i] = 1;
    }

    int ans = 0;
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        int pA = find(a[i]);
        int pB = find(a[n - i - 1]);
        if (pA != pB)
        {
            ans++;
            union_op(pA, pB);
        }
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
    //cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}