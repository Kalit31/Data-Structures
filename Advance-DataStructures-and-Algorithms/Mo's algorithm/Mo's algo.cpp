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
         Never use an iterator after erasing it.
*/

// Can use smarter sorting: https://codeforces.com/blog/entry/61203
int block_size;

struct Query
{
    int ind, l, r;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

const int N = 300050;
int cnt[N];
int a[N];
int ans;

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
    memset(cnt, 0, sizeof(cnt));
    int n, q;
    cin >> n >> q;
    block_size = 548;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++)
    {
        queries[i].ind = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l;
        queries[i].r;
    }
    sort(queries.begin(), queries.end());
    ans = 0;
    vector<int> queryAns(q, 0);
    int r = 0;
    int l = 1;
    for (int i = 0; i < q; i++)
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
        queryAns[queries[i].ind] = ans;
    }
    for (int x : queryAns)
    {
        cout << x << endl;
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
    //  cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}