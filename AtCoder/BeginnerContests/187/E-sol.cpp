#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (ll) a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ld long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template <typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    return os << '(' << p.F << "," << p.S << ')';
}

const int N = 200005;

template <typename T = long long>
struct fenwick
{
    T a[N], bit[N];
    int n;
    fenwick()
    {
        for (int i = 1; i <= N - 2; ++i)
            a[i] = T(0), bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += j & -j)
                bit[j] += a[i];
    }
    void update(int j, T val)
    {
        for (; j <= n; j += j & -j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for (; r; r -= r & -r)
            u += bit[r];
        return u;
    }
    T query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
// call fenw.build(n);
fenwick<ll> fenw;
vector<int> v[N];
int in[N], out[N], cur = 1;
int dep[N];
void dfs(int s, int p)
{
    in[s] = cur++;
    for (auto j : v[s])
    {
        if (j != p)
        {
            dep[j] = dep[s] + 1;
            dfs(j, s);
        }
    }
    out[s] = cur - 1;
}

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<pii> ed;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        ed.pb({x, y});
        v[x].pb(y), v[y].pb(x);
    }
    dfs(1, 0);
    int Q;
    cin >> Q;
    assert(cur == n + 1);
    fenw.build(n);
    while (Q--)
    {
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        int a = ed[e].F, b = ed[e].S;
        if (t == 2)
            swap(a, b);
        if (dep[a] > dep[b])
        {
            fenw.update(in[a], x);
            fenw.update(out[a] + 1, -x);
        }
        else
        {
            fenw.update(in[1], x);
            fenw.update(in[b], -x);
            fenw.update(out[b] + 1, x);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << fenw.get(in[i]) << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef runSieve
    sieve();
#endif
#ifdef NCR
    initialize();
#endif
    int TESTS = 1;
    //cin>>TESTS;
    while (TESTS--)
        _runtimeTerror_();
    return 0;
}