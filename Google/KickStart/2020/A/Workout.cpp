#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
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

int check(vector<int> &m, int diff)
{
    int insert = 0;
    for (int i = 1; i < m.size(); i++)
    {
        int d = m[i] - m[i - 1];
        if (d <= diff)
        {
            continue;
        }
        insert += ceil((1.0 * d) / diff) - 1;
    }
    return insert;
}

void solve(int t)
{
    int n, k;
    cin >> n >> k;
    vector<int> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    int h = 0;
    for (int i = 1; i < n; i++)
    {
        h = max(h, m[i] - m[i - 1]);
    }
    //deb(h);
    int l = 1;
    int ans = h;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        // deb(mid);
        if (check(m, mid) <= k)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << "Case #" << t << ": " << ans << endl;
}

int main()
{
    //     fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}