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

vector<int> parent;

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    parent[b] = a;
}

ll my_pow(ll a, ll n, ll m = INF)
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

void solveOpt()
{
    ll c, n, m;
    cin >> c >> n >> m;
    parent.clear();
    parent.resize(c + 1);
    for (int i = 1; i <= c; i++)
    {
        make_set(i);
    }
    int x;
    int l, r;
    vector<array<int, 3>> intervals;
    for (int i = 1; i <= c; i++)
    {
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> l >> r;
            intervals.push_back({l, r, i});
        }
    }
    sort(intervals.begin(), intervals.end());

    int prevClub;
    int prevEnd = 0;
    int cntNoClubs = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        int currStart = intervals[i][0];
        int currEnd = intervals[i][1];
        int currClub = intervals[i][2];

        if (prevEnd >= currStart)
        {
            union_sets(currClub, prevClub);
            prevEnd = max(prevEnd, currEnd);
        }
        else
        {
            cntNoClubs += (currStart - prevEnd - 1);
            prevEnd = currEnd;
            prevClub = currClub;
        }
    }
    cntNoClubs += (n - prevEnd);
    set<int> diff;
    for (int i = 1; i <= c; i++)
    {
        diff.insert(find_set(i));
    }
    cout << my_pow(m, diff.size() + cntNoClubs, mod2) << endl;
}

void solve()
{
    ll c, n, m;
    cin >> c >> n >> m;
    vector<int> whichClass(n + 1, -1);
    int x;
    int l, r;
    for (int i = 1; i <= c; i++)
    {
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> l >> r;
            for (int k = l; k <= r; k++)
            {
                if (whichClass[k] != -1 && whichClass[k] != i)
                {
                    int clas = whichClass[k];
                    for (int l = 1; l <= n; l++)
                    {
                        if (whichClass[l] == clas)
                        {
                            whichClass[l] = i;
                        }
                    }
                }
                else
                {
                    whichClass[k] = i;
                }
            }
        }
    }
    set<int> diff;
    for (int i = 1; i <= n; i++)
    {
        diff.insert(whichClass[i]);
    }
    cout << my_pow(m, diff.size(), mod2) << endl;
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
    while (T--)
    {
        solveOpt();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}