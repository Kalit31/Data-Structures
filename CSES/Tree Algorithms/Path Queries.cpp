#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

const int N = 2e5 + 5;
vector<int> adjList[N];
ll value[N];
int timer = 0, st[N], en[N];

void dfs(int node, int parent)
{
    st[node] = timer++;
    for (int i : adjList[node])
    {
        if (i != parent)
        {
            dfs(i, node);
        }
    }
    en[node] = timer - 1;
}

struct SegmentTree
{
    int n;
    vector<int> lo, hi;
    vector<ll> vals, delta;

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

    void update(int a, int b, ll val)
    {
        updateNodes(1, a, b, val);
    }

    void propagate(int i)
    {
        delta[2 * i] += delta[i];
        delta[2 * i + 1] += delta[i];
        delta[i] = 0;
    }

    void updateHelper(int i)
    {
        vals[i] = vals[2 * i] + delta[2 * i] + vals[2 * i + 1] + delta[2 * i + 1];
    }

    void updateNodes(int i, int a, int b, ll val)
    {
        // cout << "I: " << i << "- (" << lo[i] << "," << hi[i] << ")" << endl;
        if (lo[i] > b || hi[i] < a)
        {
            return;
        }
        //complete cover
        if (lo[i] >= a && b >= hi[i])
        {
            delta[i] += val;
            return;
        }

        //partial cover
        propagate(i); //push change to children
        updateNodes(2 * i, a, b, val);
        updateNodes(2 * i + 1, a, b, val);
        updateHelper(i);
    }

    ll sum(int a, int b)
    {
        return sum(1, a, b);
    }

    ll sum(int i, int a, int b)
    {
        if (lo[i] > b || hi[i] < a)
        {
            return 0;
        }
        if (a <= lo[i] && hi[i] <= b)
        {
            return vals[i] + delta[i];
        }

        propagate(i);

        //do not update my min, bcoz minLeft and minRight may be partial covers of the subtrees

        ll sumLeft = sum(2 * i, a, b);
        ll sumRight = sum(2 * i + 1, a, b);

        updateHelper(i);

        ll ans = sumLeft + sumRight;
        return ans;
    }
};

SegmentTree tree;

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    tree.init(n);

    dfs(0, -1);

    for (int i = 0; i < n; i++)
    {
        tree.update(st[i], en[i], value[i]);
    }

    int type;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            ll change = x - value[s];
            tree.update(st[s], en[s], change);
            value[s] = x;
        }
        else
        {
            int s;
            cin >> s;
            s--;
            cout << tree.sum(st[s], st[s]) << endl;
        }
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}