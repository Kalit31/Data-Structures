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
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

//Does not work yet :(

struct SegmentTree
{
    int n;
    vector<int> lo, hi;
    vector<int> vals, delta;

    void init(int n)
    {
        this->n = n;
        lo.clear();
        lo.resize(4 * n + 1);
        hi.clear();
        hi.resize(4 * n + 1);
        vals.clear();
        vals.resize(4 * n + 1, 0);
        delta.clear();
        delta.resize(4 * n + 1, 0);
        initializeNodes(1, 0, n - 1);
    }

    void initializeNodes(int i, int a, int b)
    {
        lo[i] = a;
        hi[i] = b;

        if (a == b)
        {
            vals[i] = 0;
            return;
        }
        int mid = (a + b) / 2;
        initializeNodes(2 * i, a, mid);
        initializeNodes(2 * i + 1, mid + 1, b);
        updateHelper(i);
    }

    void update(int a, int val)
    {
        updateNodes(1, a, val);
    }

    void updateHelper(int i)
    {
        vals[i] = __gcd(vals[2 * i], vals[2 * i + 1]);
    }

    void updateNodes(int i, int pos, int val)
    {
        if (lo[i] == hi[i])
        {
            vals[i] = val;
        }
        int mid = (lo[i] + hi[i]) / 2;
        if (pos <= mid)
        {
            updateNodes(2 * i, pos, val);
        }
        else
        {
            updateNodes(2 * i + 1, pos, val);
        }
        updateHelper(i);
    }

    int query(int a, int b)
    {
        return query(1, a, b);
    }

    int query(int i, int a, int b)
    {
        if (lo[i] > b || hi[i] < a)
        {
            return 0;
        }
        if (a <= lo[i] && hi[i] <= b)
        {
            return vals[i];
        }

        int left = query(2 * i, a, b);
        int right = query(2 * i + 1, a, b);

        updateHelper(i);

        int ans = __gcd(left, right);
        return ans;
    }
};

SegmentTree tree;

const int N = 5e4 + 5;
const int M = 2e5 + 5;

vector<array<ll, 3>> adjList[M];
vector<array<ll, 2>> queries[M];
int result[M];

void dfs(int curr, int parent)
{
    cout << "CURR: " << curr << endl
         << flush;
    cout << "PAR: " << parent << endl
         << flush << endl;
    for (array<ll, 2> q : queries[curr])
    {
        result[q[1]] = tree.query(1, q[0]);
    }
    cout << "SZ: " << adjList[curr].size() << endl
         << flush;

    for (array<ll, 3> v : adjList[curr])
    {
        cout << "CHILD: " << v[0] << endl
             << flush;
        if (v[0] == parent)
        {
            continue;
        }
        ll prev = tree.query(v[1], v[1]);
        cout << "PREV: " << prev << endl
             << flush;
        tree.update(v[1], __gcd(prev, v[2]));
        dfs(v[0], curr);
        tree.update(v[1], prev);
    }
}

void solve()
{
    cout << endl;
    int n, q;
    cin >> n >> q;
    ll x, y, l, a;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> l >> a;
        adjList[x].push_back({y, l, a});
        adjList[y].push_back({x, l, a});
    }

    ll c, w;
    for (int i = 0; i < q; i++)
    {
        cin >> c >> w;
        queries[c].push_back({w, i});
    }

    tree.init(M);

    dfs(1, -1);

    // for (int i = 0; i < q; i++)
    // {
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     adjList[i].clear();
    //     queries[i].clear();
    // }
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
