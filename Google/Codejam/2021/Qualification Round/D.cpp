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
#define sq(x) ((x) * (x))
#define f first
#define s second
#define pb push_back
#define eb emplace_back

int n;
void solve()
{
    cout << 1 << " " << 2 << " " << 3;
    cout << endl;
    fflush(stdout);
    int med;
    cin >> med;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    fflush(stdout);
}

int main()
{
    //     fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
    // #endif
    int T = 1;
    int q;
    cin >> T >> n >> q;
    for (int i = 1; i <= T; i++)
    {
        //  cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}