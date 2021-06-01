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

int block_size;

struct Query
{
    int ind, l, r;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

int cnt[N];
int ans;
int a[N];

//Change implementation as required
void add(int i)
{
    if (++cnt[a[i]] == 1)
    {
        ans++;
    }
}

//Change implementation as required
void remove(int i)
{
    if (--cnt[a[i]] == 0)
    {
        ans--;
    }
}

void solve()
{
    int n;
    cin >> n;
    block_size = max(1, int(pow(n, 1.0 / 2.0)));
    memset(cnt, 0, sizeof(cnt));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
        mp[value[i]] = 0;
    }

    //compression
    int compressed_val = 1;
    for (auto &it : mp)
    {
        it.second = compressed_val++;
    }
    for (int i = 0; i < n; i++)
    {
        value[i] = mp[value[i]];
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
    dfs(0, -1);
    vector<Query> queries(n);
    for (int i = 0; i < n; i++)
    {
        queries[i].ind = i;
        queries[i].l = st[i];
        queries[i].r = en[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[st[i]] = value[i];
    }

    sort(queries.begin(), queries.end());

    ans = 0;
    vector<int> queryAns(n);
    int r = -1;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        while (r < queries[i].r)
        {
            r++;
            add(r);
        }
        while (l > queries[i].l)
        {
            l--;
            add(l);
        }
        while (r > queries[i].r)
        {
            remove(r);
            r--;
        }
        while (l < queries[i].l)
        {
            remove(l);
            l++;
        }
        //    cout << queries[i].ind << " " << queries[i].l << "-" << queries[i].r << ":" << ans << endl;
        queryAns[queries[i].ind] = ans;
    }
    for (int x : queryAns)
    {
        cout << x << " ";
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}