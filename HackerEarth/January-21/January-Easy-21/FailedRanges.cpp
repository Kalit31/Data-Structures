// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FastRead             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long int
#define ll int
#define endl '\n'
#define double double
#define ld double
#define FOR(i, a, n) for (ll i = (a); i <= (n); ++i)
#define RFOR(i, a, n) for (ll i = (n); i >= (a); --i)
#define FI(i, n) for (ll i = 0; i < (n); ++i)
#define ZERO(a) memset((a), 0, sizeof((a)))
#define MINUS(a) memset((a), -1, sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(), g.end()
#define sz(x) (ll) x.size()
int fastMax(int x, int y)
{
    return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y;
}
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5 + 10;
int A[MAXN], B[MAXN];
int N, M, X, Y;

int greater_than_Xth(int K)
{
    int s = 0, e = (A[N] + B[M]);
    int ans = e;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            int req = mid - A[i];
            cnt += upper_bound(B + 1, B + M + 1, req) - B - 1;
        }
        if (cnt >= K)
            ans = mid, e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}

int less_than_Yth(int K)
{
    int s = 0, e = (A[N] + B[M]);
    int ans = s;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            int req = mid - A[i];
            cnt += upper_bound(B + 1, B + M + 1, req) - B - 1;
        }
        if (cnt < K)
            ans = mid, s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}

void solve()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    cin >> X >> Y;

    int val_start = greater_than_Xth(X) + 1;
    int val_end = less_than_Yth(Y);

    vector<pair<int, int>> sol;

    for (int i = 1; i <= N; i++)
    {
        int req_start = val_start - A[i];
        int idx_start = lower_bound(B + 1, B + M + 1, req_start) - B;

        for (int j = idx_start; j <= M; j++)
        {
            if (A[i] + B[j] > val_end)
                break;
            sol.push_back({i, j});
        }
    }

    sort(all(sol));
    cout << sz(sol) << endl;
    for (auto x : sol)
        cout << "(" << x.first << "," << x.second << ") ";
}

signed main()
{

    FastRead;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int t = 1;
    // cin>>t;
    FOR(i, 1, t)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}