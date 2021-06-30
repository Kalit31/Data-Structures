#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

void build(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        cout << from << " " << to << endl;
        return;
    }
    //move the top (n-1) disks to auxillary stack
    build(n - 1, from, aux, to);

    //move the last disk to the target stack
    cout << from << " " << to << endl;

    //move the earlier shifted (n-1) disks from the auxillary stack to target stack
    build(n - 1, aux, to, from);
}

void solve()
{
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    build(n, 1, 3, 2);
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