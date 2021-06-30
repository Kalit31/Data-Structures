#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
        arr[i] = x;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            ans++;
        }
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int e1 = arr[a];
        int e2 = arr[b];

        set<pair<int, int>> pairsAffected;

        if (e1 > 1)
        {
            pairsAffected.insert({e1 - 1, e1});
        }
        if (e1 < n)
        {
            pairsAffected.insert({e1, e1 + 1});
        }
        if (e2 > 1)
        {
            pairsAffected.insert({e2 - 1, e2});
        }
        if (e2 < n)
        {
            pairsAffected.insert({e2, e2 + 1});
        }

        for (auto pr : pairsAffected)
        {
            if (pos[pr.first] > pos[pr.second])
            {
                ans--;
            }
        }
        swap(pos[e1], pos[e2]);
        swap(arr[a], arr[b]);

        for (auto pr : pairsAffected)
        {
            if (pos[pr.first] > pos[pr.second])
            {
                ans++;
            }
        }
        cout << ans << endl;
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