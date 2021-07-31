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
         Never use an iterator after erasing it
*/

struct FenwickTree
{
    vector<ll> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r)
    {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve()
{
    ll n, q, p;
    cin >> n >> q >> p;

    vector<FenwickTree> trees;

    for (int i = 0; i < 4; i++)
    {
        FenwickTree tree(n + 1);
        trees.push_back(tree);
    }
    vector<ll> a(n);
    vector<vector<ll>> vals(n, vector<ll>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= 4; j++)
        {
            ll curr = pow(a[i], j);
            curr -= pow(a[i] % p, j);

            int val = 0;
            while (curr != 0 && curr % p == 0)
            {
                val++;
                curr /= p;
            }
            vals[i][j - 1] = val;
            trees[j - 1].add(i, val);
        }
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll pos, val;
            cin >> pos >> val;
            pos--;
            a[pos] = val;
            for (int i = 1; i <= 4; i++)
            {
                ll curr = pow(a[pos], i);
                curr -= pow(a[pos] % p, i);
                int cval = 0;
                while (curr != 0 && curr % p == 0)
                {
                    cval++;
                    curr /= p;
                }
                int orig = vals[pos][i - 1];
                vals[pos][i - 1] = cval;
                int delta = cval - orig;
                trees[i - 1].add(pos, delta);
            }
        }
        else
        {
            ll s, l, r;
            cin >> s >> l >> r;
            s--;
            l--;
            r--;
            int ans = trees[s].sum(l, r);
            cout << ans << " ";
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}