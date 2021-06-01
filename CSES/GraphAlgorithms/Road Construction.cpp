#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
const ll INF = 1e17;
const ll NEGINF = -1 * INF;

vector<int> dsuf;
vector<int> sizeComp;
int largestComponent = 1;

//FIND operation
int find(int v)
{
    if (dsuf[v] == v)
        return v;
    return dsuf[v] = find(dsuf[v]); //Path Compression
}

void union_op(int pA, int pB)
{
    if (sizeComp[pA] > sizeComp[pB])
    {
        dsuf[pB] = dsuf[pA];
        sizeComp[pA] += sizeComp[pB];
        largestComponent = max(largestComponent, sizeComp[pA]);
    }
    else
    {
        dsuf[pA] = dsuf[pB];
        sizeComp[pB] += sizeComp[pA];
        largestComponent = max(largestComponent, sizeComp[pB]);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    dsuf.resize(n);
    for (int i = 0; i < n; i++)
    {
        dsuf[i] = i;
    }
    sizeComp.resize(n);
    for (int i = 0; i < n; i++)
    {
        sizeComp[i] = 1;
    }
    int a, b;
    int components = n;
    largestComponent = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        int pA = find(a);
        int pB = find(b);
        if (pA != pB)
        {
            components--;
            union_op(pA, pB);
        }
        cout << components << " " << largestComponent << endl;
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