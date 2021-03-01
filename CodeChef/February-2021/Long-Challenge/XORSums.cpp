#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define deb(x) cout << #x << " " << x << endl;
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()

const ll INF = 1e18;
const ll mod = (ll)998244353;

ll power(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

vector<ll> fact;
vector<ll> factInv;

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

void preFact(int n)
{
    for (ll i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        factInv[i] = modInverse(fact[i], mod);
    }
}

ll nCrModPFermat(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    ll ans = (fact[n] * factInv[r]) % mod;
    ans = (ans * factInv[n - r]) % mod;
    return ans;
}

// template code for NTT
inline int mul(int a, int b) { return (a * 1ll * b) % mod; }

inline int power2(int a, int b)
{
    int rt = 1;
    while (b > 0)
    {
        if (b & 1)
            rt = mul(rt, a);
        a = mul(a, a);
        b >>= 1;
    }
    return rt;
}
inline int inv(int a) { return power2(a, mod - 2); }

int base = 1;
vector<int> roots = {0, 1};
vector<int> rev = {0, 1};
const int max_base = 20;
const int root = 565042129;

void ensure_base(int nbase)
{
    if (nbase <= base)
    {
        return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++)
    {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase)
    {
        int z = power2(root, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); i++)
        {
            roots[i << 1] = roots[i];
            roots[(i << 1) + 1] = mul(roots[i], z);
        }
        base++;
    }
}
void fft(vector<int> &a)
{
    int n = (int)a.size();
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++)
    {
        if (i < (rev[i] >> shift))
        {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1)
    {
        for (int i = 0; i < n; i += 2 * k)
        {
            for (int j = 0; j < k; j++)
            {
                int x = a[i + j];
                int y = mul(a[i + j + k], roots[j + k]);
                a[i + j] = x + y - mod;
                if (a[i + j] < 0)
                    a[i + j] += mod;
                a[i + j + k] = x - y + mod;
                if (a[i + j + k] >= mod)
                    a[i + j + k] -= mod;
            }
        }
    }
}
vector<int> multiply(vector<int> a, vector<int> b)
{
    int need = (int)(a.size() + b.size() - 1);
    int nbase = 0;
    while ((1 << nbase) < need)
        nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++)
    {
        a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
}

void solve()
{
    int n;
    cin >> n;
    int nn = 1;
    while (nn < 2 * n)
    {
        nn <<= 1;
    }
    fact.resize(nn + 1, 1);
    factInv.resize(nn + 1, 1);
    preFact(nn);
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> cntOnes(31, 0);
    vector<int> cntZeros(31, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if (a[i] & (1ll << j))
            {
                cntOnes[j]++;
            }
            else
            {
                cntZeros[j]++;
            }
        }
    }
    vector<ll> ans(n + 1, 0);
    vector<vector<int>> ans2(n + 1, vector<int>(31, 0));
    for (int j = 0; j < 31; j++)
    {
        int cnt1 = cntOnes[j];
        int cnt0 = cntZeros[j];

        vector<int> f1(cnt1 + 1, 0);
        for (int i = 1; i <= cnt1; i += 2)
        {
            f1[i] = nCrModPFermat(cnt1, i);
        }
        vector<int> f2(cnt0 + 1, 0);
        for (int i = 0; i <= cnt0; i++)
        {
            f2[i] = nCrModPFermat(cnt0, i);
        }

        vector<int> f3 = multiply(f1, f2);

        for (int i = 1; i <= n; i++)
        {
            ans2[i][j] = f3[i];
        }
    }

    ll currAns = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            currAns = (currAns + ((((1ll << j) % mod) * ans2[i][j]) % mod)) % mod;
        }
        ans[i] = currAns;
    }

    int q;
    cin >> q;
    int m;
    while (q--)
    {
        cin >> m;
        cout << ans[m] << endl;
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}